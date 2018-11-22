#ifdef MNDTLIBRARY_EXPORTS
#define MNDTLIBRARY_API __declspec(dllexport)
#include "Library.h"
#include "LBP.h"
#include "HOG.h"
#include "Segment.h"

extern "C" MNDTLIBRARY_API void mndtWrite(C_UCHAE* msg)
{
	MNDT::Write(msg);
}

extern "C" MNDTLIBRARY_API void mndtChangeColor(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_UINT32 type)
{
	Library lib;
	lib.ChangeColor(src, pur
		, width, height
		, type);
}

extern "C" MNDTLIBRARY_API void mndtAdjustmentHSV(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_INT32 H, C_INT32 S, C_INT32 V)
{
	Library lib;
	lib.AdjustmentHSV(src, pur
		, width, height
		, H, S, V);
}

extern "C" MNDTLIBRARY_API void mndtAdjustmentYCbCr(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_INT32 Y, C_INT32 Cb, C_INT32 Cr)
{
	Library lib;
	lib.AdjustmentYCbCr(src, pur
		, width, height
		, Y, Cb, Cr);
}

extern "C" MNDTLIBRARY_API void mndtImagePadding8bit(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_INT32 pad)
{
	Library lib;
	lib.ImagePadding8bit(src, pur
		, width, height
		, pad);
}

extern "C" MNDTLIBRARY_API void mndtImagePadding24bit(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_INT32 pad)
{
	Library lib;
	lib.ImagePadding24bit(src, pur
		, width, height
		, pad);
}

extern "C" MNDTLIBRARY_API void mndtBlur8bit(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_UINT32 size)
{
	Library lib;
	lib.Blur8bit(src, pur
		, width, height
		, size);
}

extern "C" MNDTLIBRARY_API void mndtBlurGauss8bit(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_UINT32 size, C_FLOAT sigma)
{
	Library lib;
	lib.BlurGauss8bit(src, pur
		, width, height
		, size, sigma);
}

extern "C" MNDTLIBRARY_API void mndtBlurGauss24bit(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_UINT32 size, C_FLOAT sigma)
{
	Library lib;
	lib.BlurGauss24bit(src, pur
		, width, height
		, size, sigma);
}

extern "C" MNDTLIBRARY_API void mndtMedianBlur8bit(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_UINT32 size)
{
	Library lib;
	lib.MedianBlur8bit(src, pur
		, width, height
		, size);
}

extern "C" MNDTLIBRARY_API void mndtBilateralBlur8bit(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_FLOAT spaceSigma, C_FLOAT colorSigma
	, C_UINT32 size)
{
	Library lib;
	lib.BilateralBlur8bit(src, pur
		, width, height
		, spaceSigma, colorSigma
		, size);
}

extern "C" MNDTLIBRARY_API void mndtHistogram8bit(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height)
{
	Library lib;
	lib.Histogram8bit(src, pur
		, width, height);
}

extern "C" MNDTLIBRARY_API void mndtHistogramEqualization8bit(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height)
{
	Library lib;
	lib.HistogramEqualization8bit(src, pur
		, width, height);
}

extern "C" MNDTLIBRARY_API double mndtCompareHistogram(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height)
{
	Library lib;
	return lib.CompareHistogram(src, pur
		, width, height);
}

extern "C" MNDTLIBRARY_API void mndtChannel(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_UINT32 channel)
{
	Library lib;
	lib.Channel(src, pur
		, width, height
		, channel);
}

extern "C" MNDTLIBRARY_API void mndtBackProjection(C_UCHAE* src, UCHAE* pur
	, C_UINT32 srcWidth, C_UINT32 srcHeight
	, C_UINT32* histogram
	, C_UCHAE minRange, C_UCHAE maxRange
	, C_UCHAE bin)
{
	Library lib;
	lib.BackProjection(src, pur
		, srcWidth, srcHeight
		, histogram
		, minRange, maxRange
		, bin);
}

extern "C" MNDTLIBRARY_API void mndtSetHistogram8bit(C_UCHAE* src, int32_t* histogram
	, C_UINT32 hisWidth, C_UINT32 hisHeight
	, C_UCHAE minRange, C_UCHAE maxRange
	, C_UCHAE bin)
{
	Library lib;
	lib.SetHistogram8bit(src, histogram
		, hisWidth, hisHeight
		, minRange, maxRange
		, bin);
}

extern "C" MNDTLIBRARY_API void mndtSetNormalizedHistogram8bit(int32_t* histogram
	, C_UINT32 bin
	, C_UCHAE maxRange)
{
	Library lib;
	lib.SetNormalizedHistogram8bit(histogram
		, bin
		, maxRange);
}

extern "C" MNDTLIBRARY_API void mndtThreshold8bit(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_UINT32 thresh)
{
	Library lib;
	lib.Threshold8bit(src, pur
		, width, height
		, thresh);
}

extern "C" MNDTLIBRARY_API void mndtMeanShift(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_UINT32* rectPoint
	, C_UINT32 times
	, C_DOUBLE threshold)
{
	Library lib;
	lib.MeanShift(src, pur
		, width, height
		, rectPoint
		, times
		, threshold);
}

extern "C" MNDTLIBRARY_API void mndtRotate8bit(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_UINT32 type)
{
	Library lib;
	lib.Rotate8bit(src, pur
		, width, height
		, static_cast<MNDT::RotateType>(type));
}

extern "C" MNDTLIBRARY_API void mndtResize8bit(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_UINT32 reWidth, C_UINT32 reHeight
	, C_UINT32 type)
{
	Library lib;
	lib.Resize8bit(src, pur
		, width, height
		, reWidth, reHeight
		, (MNDT::ResizeType)type);
}

extern "C" MNDTLIBRARY_API void mndtPyramidDown8bit(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height)
{
	Library lib;
	lib.PyramidDown8bit(src, pur
		, width, height);
}

extern "C" MNDTLIBRARY_API void mndtPyramidUp8bit(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height)
{
	Library lib;
	lib.PyramidUp8bit(src, pur
		, width, height);
}

extern "C" MNDTLIBRARY_API void mndtSetAffineTransform(C_FLOAT* affine
	, float* baseX, float* baseY
	, C_UINT32 row, C_UINT32 col)
{
	float** affine2D = new float*[row];

	for (UINT32 index = 0; index < row; index++)
	{
		affine2D[index] = new float[col];
		memcpy(affine2D[index], affine, col * sizeof(C_FLOAT));
		affine += col;
	}

	Library lib;
	lib.SetAffineTransform(affine2D
		, baseX, baseY
		, row, col);

	for (UINT32 index = 0; index < row; index++)
	{
		delete[] affine2D[index];
		affine2D[index] = nullptr;
	}

	delete[] affine2D;
	affine2D = nullptr;
}

extern "C" MNDTLIBRARY_API void mndtAffine8bit(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, float* baseX, float* baseY)
{
	Library lib;
	lib.Affine8bit(src, pur
		, width, height
		, baseX, baseY);
}

extern "C" MNDTLIBRARY_API void mndtSobel24bit(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, const bool dx, const bool dy)
{
	Library lib;
	lib.SobelVisualization24bit(src, pur
		, width, height
		, dx, dy);
}

extern "C" MNDTLIBRARY_API void mndtSobelEdge8bit(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height)
{
	Library lib;
	lib.SobelEdgeView8bit(src, pur
		, width, height);
}

extern "C" MNDTLIBRARY_API void mndtSegmentImage(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_FLOAT sigma, C_FLOAT threshold, C_UINT32 minSize
	, UINT32* numCss)
{
	Segment segment;
	GraphTree* graphTree = new GraphTree(width * height);

	segment.SegmentImage(src, pur
		, width, height
		, sigma, threshold, minSize
		, graphTree);
	*numCss = graphTree->NumSets();


	Image purImage(pur, width, height, MNDT::ImageType::BGR_24BIT);

	segment.Visualization(purImage, graphTree);

	delete graphTree;
	graphTree = nullptr;
}

extern "C" MNDTLIBRARY_API void mndtSelectiveSearch(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_FLOAT sigma, C_FLOAT threshold, C_UINT32 minSize
	, UINT32* numCss)
{
	Segment segment;

	segment.SelectiveSearch(src, pur
		, width, height
		, sigma, threshold, minSize);
}

extern "C" MNDTLIBRARY_API void mndtOriginalLBP(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height)
{
	LBP lbp;

	lbp.OriginalLBP(src, pur
		, width, height);
}

extern "C" MNDTLIBRARY_API void mndtCircularLBP(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height)
{
	LBP lbp;

	lbp.CircularLBP(src, pur
		, width, height);
}

extern "C" MNDTLIBRARY_API void mndtInvariantLBP(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height)
{
	LBP lbp;

	lbp.InvariantLBP(src, pur
		, width, height);
}

extern "C" MNDTLIBRARY_API void mndtEquivalentLBP(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height)
{
	LBP lbp;

	lbp.EquivalentLBP(src, pur
		, width, height);
}

extern "C" MNDTLIBRARY_API void mndtMultiScaleBlockLBP(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height)
{
	LBP lbp;

	lbp.MultiScaleBlockLBP(src, pur
		, width, height);
}

extern "C" MNDTLIBRARY_API void mndtSEMultiScaleBlockLBP(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height)
{
	LBP lbp;

	lbp.SEMultiScaleBlockLBP(src, pur
		, width, height);
}

extern "C" MNDTLIBRARY_API void mndtLBPHistogram(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_UINT32 gridX, C_UINT32 gridY
	, C_UINT32 bin)
{
	LBP lbp;

	lbp.LBPHistogram(src, pur
		, width, height
		, gridX, gridY
		, bin);
}

extern "C" MNDTLIBRARY_API void mndtGamma(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_DOUBLE gamma)
{
	Library lib;

	lib.Gamma8bit(src, pur
		, width, height
		, gamma);
}

extern "C" MNDTLIBRARY_API void mndtHOGGradient(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height)
{
	HOG hog;

	hog.GradienView(src, pur
		, width, height);
}

extern "C" MNDTLIBRARY_API void mndtHOGCellHistogram(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_UINT32 cellX, C_UINT32 cellY)
{
	HOG hog;

	float* histogram = new float[hog.CellHisTotalSize(width, height)]{ 0 };

	hog.CellHistogram(src, width, height
		, histogram);

	delete[] histogram;
	histogram = nullptr;
}

extern "C" MNDTLIBRARY_API void mndtHOGBlockHistogram(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_UINT32 cellX, C_UINT32 cellY
	, C_UINT32 blockX, C_UINT32 blockY)
{
	HOG hog;
	float* histogram = new float[hog.BlockHisTotalSize(width, height)]{ 0 };

	hog.BlockHistogram(src, width, height
		, histogram);

	delete[] histogram;
	histogram = nullptr;
}


extern "C" MNDTLIBRARY_API void mndtHOGView(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_UINT32 cellX, C_UINT32 cellY
	, C_UINT32 blockX, C_UINT32 blockY)
{
	HOG hog(cellX, cellY, blockX, blockY);

	hog.HOGBlockView(src, pur
		, width, height);
}

extern "C" MNDTLIBRARY_API void mndtHOGCellView(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_UINT32 cellX, C_UINT32 cellY)
{
	HOG hog(cellX, cellY);

	hog.HOGCellView(src, pur
		, width, height);
}

extern "C" MNDTLIBRARY_API void mndtHOGBlockView(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_UINT32 cellX, C_UINT32 cellY
	, C_UINT32 blockX, C_UINT32 blockY)
{
	HOG hog(cellX, cellY, blockX, blockY);

	hog.HOGBlockView(src, pur
		, width, height);
}


extern "C" MNDTLIBRARY_API void mndtHoughLines(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_FLOAT rho, C_FLOAT theta, C_UINT32 threshold)
{
	Library lib;

	lib.HoughLines(src, pur
		, width, height
		, rho, theta, threshold);
}

extern "C" MNDTLIBRARY_API void mndtHoughCircles(C_UCHAE* src, UCHAE* pur
	, C_UINT32 width, C_UINT32 height
	, C_FLOAT minRadius, C_FLOAT maxRadius, C_UINT32 threshold)
{
	Library lib;

	lib.HoughCircles(src, pur
		, width, height
		, minRadius, maxRadius, threshold);
}

#else
#define MNDTLIBRARY_API __declspec(dllimport)
#endif