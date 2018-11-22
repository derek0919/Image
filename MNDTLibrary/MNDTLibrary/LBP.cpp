#include "LBP.h"

LBP::LBP()
{
}

LBP::~LBP()
{
}

void LBP::OriginalLBP(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height)
{
	C_UINT32 padWidth = width + 2;
	C_UINT32 padHeight = height + 2;
	UCHAE* padData = new UCHAE[padWidth * padHeight]{ 0 };
	Library lib;

	lib.ImagePadding8bit(src, padData, width, height, 1);

	Image padImage(padData, padWidth, padHeight, MNDT::ImageType::GRAY_8BIT);

	for (UINT32 row = 1; row < padHeight - 1; row++)
	{
		for (UINT32 col = 1; col < padWidth - 1; col++)
		{
			UCHAE sum = 0;

			sum |= static_cast<UCHAE>(padImage.image[row - 1][col - 1] > padImage.image[row][col]) << 7;
			sum |= static_cast<UCHAE>(padImage.image[row - 1][col] > padImage.image[row][col]) << 6;
			sum |= static_cast<UCHAE>(padImage.image[row - 1][col + 1] > padImage.image[row][col]) << 5;
			sum |= static_cast<UCHAE>(padImage.image[row][col + 1] > padImage.image[row][col]) << 4;
			sum |= static_cast<UCHAE>(padImage.image[row + 1][col + 1] > padImage.image[row][col]) << 3;
			sum |= static_cast<UCHAE>(padImage.image[row + 1][col] > padImage.image[row][col]) << 2;
			sum |= static_cast<UCHAE>(padImage.image[row + 1][col - 1] > padImage.image[row][col]) << 1;
			sum |= static_cast<UCHAE>(padImage.image[row][col - 1] > padImage.image[row][col]);

			*pur = sum;
			pur++;
		}

	}

	delete[] padData;
	padData = nullptr;
}

void LBP::CircularLBP(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_UINT32 radius, C_UINT32 bin)
{
	C_UINT32 padWidth = width + (radius << 1);
	C_UINT32 padHeight = height + (radius << 1);
	UCHAE* padData = new UCHAE[padWidth * padHeight]{ 0 };
	Library lib;

	lib.ImagePadding8bit(src, padData, width, height, radius);

	Image padImage(padData, padWidth, padHeight, MNDT::ImageType::GRAY_8BIT);
	Image purImage(pur, width, height, MNDT::ImageType::GRAY_8BIT);

	UINT32 offsetBase = bin - 1;

	for (UINT32 index = 0; index < bin; index++)
	{
		C_FLOAT centerX = MNDT::FixValue(static_cast<float>(radius * cos(2.0 * MNDT::PI * index / bin)));
		C_FLOAT centerY = MNDT::FixValue(static_cast<float>(radius * sin(2.0 * MNDT::PI * index / bin)));

		C_INT32 x1 = static_cast<int32_t>(floor(centerX));
		C_INT32 y1 = static_cast<int32_t>(floor(centerX));
		C_INT32 x2 = static_cast<int32_t>(ceil(centerX));
		C_INT32 y2 = static_cast<int32_t>(ceil(centerX));

		C_FLOAT xOffset = centerX - x1;
		C_FLOAT yOffset = centerY - y1;

		//(y, x) -> (0, 0), (0, 1), (1, 0), (1, 1)
		C_FLOAT w1 = (1.0f - xOffset) * (1.0f - yOffset);
		C_FLOAT w2 = xOffset * (1.0f - yOffset);
		C_FLOAT w3 = (1.0f - xOffset) * yOffset;
		C_FLOAT w4 = xOffset * yOffset;

		for (UINT32 row = radius; row < padHeight - radius; row++)
		{
			for (UINT32 col = radius; col < padWidth - radius; col++)
			{
				UCHAE pix = 0;
				pix = static_cast<UCHAE>(padImage.image[row + y1][col + x1] * w1
					+ padImage.image[row + y1][col + x2] * w2
					+ padImage.image[row + y2][col + x1] * w3
					+ padImage.image[row + y2][col + x2] * w4);

				purImage.image[row - radius][col - radius] |= (static_cast<UCHAE>(pix > padImage.image[row][col]) << offsetBase);
			}
		}
		offsetBase--;
	}

	delete[] padData;
	padData = nullptr;
}

void  LBP::InvariantLBP(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_INT32 radius, C_UINT32 bin)
{
	CircularLBP(src, pur
		, width, height
		, radius, bin);

	Image purImage(pur, width, height, MNDT::ImageType::GRAY_8BIT);

	for (UINT32 row = 0; row < height; row++)
	{
		for (UINT32 col = 0; col < width; col++)
		{
			// 使用位移(二進位)方式循環一次
			UCHAE originalPix = purImage.image[row][col];
			UCHAE minPix = originalPix;

			for (UINT32 index = 1; index < bin; index++)
			{
				C_UCHAE temp = (originalPix >> index) | (originalPix << index);
				if (minPix > temp)
				{
					minPix = temp;
				}
			}

			purImage.image[row][col] = minPix;
		}
	}

}

void LBP::EquivalentLBP(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_INT32 radius, C_UINT32 bin)
{
	CircularLBP(src, pur
		, width, height
		, radius, bin);

	Image purImage(pur, width, height, MNDT::ImageType::GRAY_8BIT);
	UCHAE table[256] = { 0 };

	EquivalentTable(table);

	for (UINT32 row = 0; row < height; row++)
	{
		for (UINT32 col = 0; col < width; col++)
		{
			purImage.image[row][col] = table[purImage.image[row][col]];
		}
	}
}

void LBP::EquivalentTable(UCHAE* table)
{
	UCHAE pix = 1;

	for (UINT32 index = 0; index < 256; index++)
	{
		UINT32 count = 0;
		std::bitset<8> binary = index;

		for (UINT32 bitIndex = 0; bitIndex < 8; bitIndex++)
		{
			if (binary[bitIndex] != binary[(bitIndex + 1) % 8])
			{
				count++;
			}
		}

		if (count < 3)
		{
			table[index] = pix;
			pix++;
		}
	}
}

void  LBP::MultiScaleBlockLBP(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_INT32 scale)
{

	C_UINT32 cellSize = scale / 3;
	C_INT32 cellRadius = cellSize >> 1;
	C_UINT32 padWidth = width + (cellRadius << 1);
	C_UINT32 padHeight = height + (cellRadius << 1);
	UCHAE* avgData = new UCHAE[width * height]{ 0 };
	UCHAE* padData = new UCHAE[padWidth * padHeight]{ 0 };
	Library lib;

	lib.ImagePadding8bit(src, padData, width, height, cellRadius);

	Image padImage(padData, padWidth, padHeight, MNDT::ImageType::GRAY_8BIT);
	Image avgImage(avgData, width, height, MNDT::ImageType::GRAY_8BIT);

	for (UINT32 row = cellRadius; row < padHeight - cellRadius; row++)
	{
		for (UINT32 col = cellRadius; col < padWidth - cellRadius; col++)
		{
			int32_t sum = 0;

			for (int32_t cellRow = -cellRadius; cellRow < cellRadius; cellRow++)
			{
				for (int32_t cellCol = -cellRadius; cellCol < cellRadius; cellCol++)
				{
					sum += padImage.image[row + cellRow][col + cellCol];
				}
			}

			avgImage.image[row - cellRadius][col - cellRadius] = static_cast<UCHAE>(sum / (cellRadius * cellRadius));
		}
	}

	delete[] padData;
	padData = nullptr;

	OriginalLBP(avgData, pur, width, height);

	delete[] avgData;
	avgData = nullptr;
}

void  LBP::SEMultiScaleBlockLBP(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_INT32 scale)
{
	UCHAE* MBLBPData = new UCHAE[width * height]{ 0 };

	MultiScaleBlockLBP(src, MBLBPData
		, width, height
		, scale);

	Library lib;
	int32_t histogram[256] = { 0 };
	int32_t sortHistogram[256] = { 0 };

	lib.SetHistogram8bit(MBLBPData, histogram
		, width, height);
	memcpy(sortHistogram, histogram, 256 * sizeof(int32_t));
	std::sort(sortHistogram, sortHistogram + 256);

	UCHAE table[256] = { 0 };

	for (UINT32 index = 0; index < 64; index++)
	{
		for (UINT32 hisIndex = 0; hisIndex < 256; hisIndex++)
		{
			if (sortHistogram[index] == histogram[hisIndex])
			{
				table[hisIndex] = index;
			}
		}
	}

	UINT32 size = height * width;

	for (UINT32 index = 0; index < size; index++)
	{
		pur[index] = table[MBLBPData[index]];
	}

	delete[] MBLBPData;
	MBLBPData = nullptr;
}

void LBP::LBPHistogram(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_UINT32 gridX, C_UINT32 gridY
	, C_UINT32 bin)
{
	Image srcImage(const_cast<UCHAE*>(src), width, height, MNDT::ImageType::GRAY_8BIT);
	C_UINT32 cellWidth = width / gridX;
	C_UINT32 cellHeight = height / gridY;
	float* histogram = new float[gridX * gridY * bin]{ 0 };

	for (UINT32 row = 0; row < height; row++)
	{
		UINT32 hisRowIndex = row / cellHeight * gridX;

		for (UINT32 col = 0; col < width; col++)
		{
			UINT32 hisColIndex = col / cellWidth;
			UINT32 hisIndex = (hisColIndex + hisRowIndex) * bin;

			histogram[hisIndex + (srcImage.image[row][col] % bin)]++;
		}
	}

	Library lib;
	C_UINT32 histogramSize = gridX * gridY;

	for (UINT32 index = 0; index < histogramSize; index++)
	{
		lib.SetNormalizedHistogram8bit(histogram + index * bin, bin, MNDT::Normalized::L1);
	}

	//C_UINT32 allSize = gridX * gridY * bin;

	//for (UINT32 index = 0; index < allSize; index++)
	//{
	//	MNDT::Write(histogram[index]);
	//	MNDT::Write(" ");
	//}
	//MNDT::Write("\n\n\n\n");

	delete[] histogram;
	histogram = nullptr;
}