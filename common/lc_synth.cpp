#include "lc_global.h"
#include "lc_synth.h"
#include "lc_library.h"
#include "lc_application.h"
#include "lc_file.h"
#include "lc_meshloader.h"
#include "pieceinf.h"
#include <locale.h>

void lcSynthInit()
{
	lcPiecesLibrary* Library = lcGetPiecesLibrary();

	struct lcHoseInfo
	{
		const char* PartID;
		lcSynthType Type;
		float Length;
		int NumSections;
	};

	lcHoseInfo HoseInfo[] =
	{
		{ "73590a.dat",   lcSynthType::HOSE_FLEXIBLE,    140.0f,   51 }, // Hose Flexible  8.5L without Tabs
		{ "73590b.dat",   lcSynthType::HOSE_FLEXIBLE,    140.0f,   51 }, // Hose Flexible  8.5L with Tabs
		{ "76263.dat",    lcSynthType::FLEX_SYSTEM_HOSE,   60.0f,  29 }, // Technic Flex-System Hose  3L (60LDU)
		{ "76250.dat",    lcSynthType::FLEX_SYSTEM_HOSE,   80.0f,  39 }, // Technic Flex-System Hose  4L (80LDU)
		{ "76307.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  100.0f,  49 }, // Technic Flex-System Hose  5L (100LDU)
		{ "76279.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  120.0f,  59 }, // Technic Flex-System Hose  6L (120LDU)
		{ "76289.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  140.0f,  69 }, // Technic Flex-System Hose  7L (140LDU)
		{ "76260.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  160.0f,  79 }, // Technic Flex-System Hose  8L (160LDU)
		{ "76324.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  180.0f,  89 }, // Technic Flex-System Hose  9L (180LDU)
		{ "76348.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  200.0f,  99 }, // Technic Flex-System Hose 10L (200LDU)
		{ "71505.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  220.0f, 109 }, // Technic Flex-System Hose 11L (220LDU)
		{ "71175.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  240.0f, 119 }, // Technic Flex-System Hose 12L (240LDU)
		{ "71551.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  260.0f, 129 }, // Technic Flex-System Hose 13L (260LDU)
		{ "71177.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  280.0f, 139 }, // Technic Flex-System Hose 14L (280LDU)
		{ "71194.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  300.0f, 149 }, // Technic Flex-System Hose 15L (300LDU)
		{ "71192.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  320.0f, 159 }, // Technic Flex-System Hose 16L (320LDU)
		{ "76270.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  340.0f, 169 }, // Technic Flex-System Hose 17L (340LDU)
		{ "71582.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  360.0f, 179 }, // Technic Flex-System Hose 18L (360LDU)
		{ "22463.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  380.0f, 189 }, // Technic Flex-System Hose 19L (380LDU)
		{ "76276.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  400.0f, 199 }, // Technic Flex-System Hose 20L (400LDU)
		{ "70978.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  420.0f, 209 }, // Technic Flex-System Hose 21L (420LDU)
		{ "76252.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  440.0f, 219 }, // Technic Flex-System Hose 22L (440LDU)
		{ "76254.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  460.0f, 229 }, // Technic Flex-System Hose 23L (460LDU)
		{ "76277.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  480.0f, 239 }, // Technic Flex-System Hose 24L (480LDU)
		{ "53475.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  520.0f, 259 }, // Technic Flex-System Hose 26L (520LDU)
		{ "76280.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  560.0f, 279 }, // Technic Flex-System Hose 28L (560LDU)
		{ "76389.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  580.0f, 289 }, // Technic Flex-System Hose 29L (580LDU)
		{ "76282.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  600.0f, 299 }, // Technic Flex-System Hose 30L (600LDU)
		{ "76283.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  620.0f, 309 }, // Technic Flex-System Hose 31L (620LDU)
		{ "57274.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  640.0f, 319 }, // Technic Flex-System Hose 32L (640LDU)
		{ "42688.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  660.0f, 329 }, // Technic Flex-System Hose 33L (660LDU)
		{ "22461.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  680.0f, 339 }, // Technic Flex-System Hose 34L (680LDU)
		{ "46305.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  800.0f, 399 }, // Technic Flex-System Hose 40L (800LDU)
		{ "76281.dat",    lcSynthType::FLEX_SYSTEM_HOSE,  900.0f, 449 }, // Technic Flex-System Hose 45L (900LDU)
		{ "22296.dat",    lcSynthType::FLEX_SYSTEM_HOSE, 1060.0f, 529 }, // Technic Flex-System Hose 53L (1060LDU)
		{ "72504.dat",    lcSynthType::RIBBED_HOSE,       31.25f,   4 }, // Technic Ribbed Hose  2L
		{ "72706.dat",    lcSynthType::RIBBED_HOSE,       50.00f,   7 }, // Technic Ribbed Hose  3L
		{ "71952.dat",    lcSynthType::RIBBED_HOSE,       75.00f,  11 }, // Technic Ribbed Hose  4L
		{ "72853.dat",    lcSynthType::RIBBED_HOSE,       93.75f,  14 }, // Technic Ribbed Hose  5L
		{ "71944.dat",    lcSynthType::RIBBED_HOSE,      112.50f,  17 }, // Technic Ribbed Hose  6L
		{ "57719.dat",    lcSynthType::RIBBED_HOSE,      131.25f,  20 }, // Technic Ribbed Hose  7L
		{ "71951.dat",    lcSynthType::RIBBED_HOSE,      150.00f,  23 }, // Technic Ribbed Hose  8L
		{ "71917.dat",    lcSynthType::RIBBED_HOSE,      175.00f,  27 }, // Technic Ribbed Hose  9L
		{ "71949.dat",    lcSynthType::RIBBED_HOSE,      193.75f,  30 }, // Technic Ribbed Hose 10L
		{ "71986.dat",    lcSynthType::RIBBED_HOSE,      212.50f,  33 }, // Technic Ribbed Hose 11L
		{ "71819.dat",    lcSynthType::RIBBED_HOSE,      231.25f,  36 }, // Technic Ribbed Hose 12L
		{ "71923.dat",    lcSynthType::RIBBED_HOSE,      275.00f,  43 }, // Technic Ribbed Hose 14L
		{ "71946.dat",    lcSynthType::RIBBED_HOSE,      293.75f,  46 }, // Technic Ribbed Hose 15L
		{ "71947.dat",    lcSynthType::RIBBED_HOSE,      312.50f,  49 }, // Technic Ribbed Hose 16L
		{ "22900.dat",    lcSynthType::RIBBED_HOSE,      331.25f,  52 }, // Technic Ribbed Hose 17L
		{ "72039.dat",    lcSynthType::RIBBED_HOSE,      350.00f,  55 }, // Technic Ribbed Hose 18L
		{ "43675.dat",    lcSynthType::RIBBED_HOSE,      375.00f,  58 }, // Technic Ribbed Hose 19L
		{ "23397.dat",    lcSynthType::RIBBED_HOSE,      468.75f,  74 }, // Technic Ribbed Hose 24L
		{ "33763.dat",    lcSynthType::RIBBED_HOSE,      512.50f,  81 }, // Technic Ribbed Hose 26L
		{ "32580.dat",    lcSynthType::FLEXIBLE_AXLE,    120.00f,  15 }, // Technic Axle Flexible  7
		{ "32199.dat",    lcSynthType::FLEXIBLE_AXLE,    200.00f,  35 }, // Technic Axle Flexible 11
		{ "55709.dat",    lcSynthType::FLEXIBLE_AXLE,    200.00f,  35 }, // Technic Axle Flexible 11
		{ "32200.dat",    lcSynthType::FLEXIBLE_AXLE,    220.00f,  40 }, // Technic Axle Flexible 12
		{ "32201.dat",    lcSynthType::FLEXIBLE_AXLE,    260.00f,  50 }, // Technic Axle Flexible 14
		{ "32202.dat",    lcSynthType::FLEXIBLE_AXLE,    300.00f,  60 }, // Technic Axle Flexible 16
		{ "32235.dat",    lcSynthType::FLEXIBLE_AXLE,    360.00f,  75 }, // Technic Axle Flexible 19
		{ "76384.dat",    lcSynthType::STRING_BRAIDED,   200.00f,  46 }, // String Braided 11L with End Studs
		{ "75924.dat",    lcSynthType::STRING_BRAIDED,   400.00f,  96 }, // String Braided 21L with End Studs
		{ "572C02.dat",   lcSynthType::STRING_BRAIDED,   800.00f, 196 }, // String Braided 41L with End Studs
		{ "73129.dat",    lcSynthType::SHOCK_ABSORBER,   110.00f,   1 }, // Technic Shock Absorber 6.5L
		{ "41838.dat",    lcSynthType::SHOCK_ABSORBER,   110.00f,   1 }, // Technic Shock Absorber 6.5L Soft
		{ "76138.dat",    lcSynthType::SHOCK_ABSORBER,   110.00f,   1 }, // Technic Shock Absorber 6.5L Stiff
		{ "76537.dat",    lcSynthType::SHOCK_ABSORBER,   110.00f,   1 }, // Technic Shock Absorber 6.5L Extra Stiff
		{ "61927C01.dat", lcSynthType::ACTUATOR,         270.00f,   1 }, // Technic Power Functions Linear Actuator (Extended)
		{ "61927.dat",    lcSynthType::ACTUATOR,         170.00f,   1 }  // Technic Power Functions Linear Actuator (Contracted)
	};

	for (unsigned int InfoIdx = 0; InfoIdx < sizeof(HoseInfo) / sizeof(HoseInfo[0]); InfoIdx++)
	{
		PieceInfo* Info = Library->FindPiece(HoseInfo[InfoIdx].PartID, nullptr, false, false);

		if (Info)
			Info->SetSynthInfo(new lcSynthInfo(HoseInfo[InfoIdx].Type, HoseInfo[InfoIdx].Length, HoseInfo[InfoIdx].NumSections, Info));
	}

//	"758C01" // Hose Flexible  12L
}

lcSynthInfo::lcSynthInfo(lcSynthType Type, float Length, int NumSections, PieceInfo* Info)
	: mPieceInfo(Info), mType(Type), mLength(Length), mNumSections(NumSections)
{
	float EdgeSectionLength = 0.0f;
	float MidSectionLength = 0.0f;
	mCenterLength = 0.0f;

	switch (mType)
	{
	case lcSynthType::HOSE_FLEXIBLE:
		EdgeSectionLength = 5.0f;
		MidSectionLength = 2.56f;
		mCenterLength = 4.56f;
		mRigidEdges = true;
		mCurve = true;
		break;

	case lcSynthType::FLEX_SYSTEM_HOSE:
		EdgeSectionLength = 1.0f;
		MidSectionLength = 2.0f;
		mRigidEdges = true;
		mCurve = true;
		break;

	case lcSynthType::RIBBED_HOSE:
		EdgeSectionLength = 6.25f;
		MidSectionLength = 6.25f;
		mRigidEdges = false;
		mCurve = true;
		break;

	case lcSynthType::FLEXIBLE_AXLE:
		EdgeSectionLength = 30.0f;
		MidSectionLength = 4.0f;
		mRigidEdges = true;
		mCurve = true;
		break;

	case lcSynthType::STRING_BRAIDED:
		EdgeSectionLength = 8.0f;
		MidSectionLength = 4.0f;
		mRigidEdges = true;
		mCurve = true;
		break;

	case lcSynthType::SHOCK_ABSORBER:
	case lcSynthType::ACTUATOR:
		EdgeSectionLength = 0.0f;
		MidSectionLength = 0.0f;
		mRigidEdges = false;
		mCurve = false;
		break;
	}

	switch (mType)
	{
	case lcSynthType::HOSE_FLEXIBLE:
	case lcSynthType::RIBBED_HOSE:
	case lcSynthType::FLEXIBLE_AXLE:
		mStart.Transform = lcMatrix44(lcMatrix33(lcVector3(0.0f, 0.0f, 1.0f), lcVector3(1.0f, 0.0f, 0.0f), lcVector3(0.0f, 1.0f, 0.0f)), lcVector3(0.0f, 0.0f, 0.0f));
		mMiddle.Transform = lcMatrix44Identity();
		mEnd.Transform = lcMatrix44(lcMatrix33(lcVector3(0.0f, 0.0f, 1.0f), lcVector3(1.0f, 0.0f, 0.0f), lcVector3(0.0f, 1.0f, 0.0f)), lcVector3(0.0f, 0.0f, 0.0f));
		break;

	case lcSynthType::FLEX_SYSTEM_HOSE:
	case lcSynthType::SHOCK_ABSORBER:
	case lcSynthType::ACTUATOR:
	case lcSynthType::STRING_BRAIDED:
		mStart.Transform = lcMatrix44Identity();
		mMiddle.Transform = lcMatrix44Identity();
		mEnd.Transform = lcMatrix44Identity();
		break;
	}

	mStart.Length = EdgeSectionLength;
	mMiddle.Length = MidSectionLength;
	mEnd.Length = EdgeSectionLength;
}

void lcSynthInfo::GetDefaultControlPoints(lcArray<lcPieceControlPoint>& ControlPoints) const
{
	ControlPoints.SetSize(2);

	float Scale = 1.0f;

	switch (mType)
	{
	case lcSynthType::HOSE_FLEXIBLE:
		Scale = 12.0f;
		break;

	case lcSynthType::FLEX_SYSTEM_HOSE:
		Scale = 12.0f;
		break;

	case lcSynthType::RIBBED_HOSE:
		Scale = 80.0f;
		break;

	case lcSynthType::FLEXIBLE_AXLE:
		Scale = 12.0f;
		break;

	case lcSynthType::STRING_BRAIDED:
		Scale = 12.0f;
		break;

	case lcSynthType::SHOCK_ABSORBER:
	case lcSynthType::ACTUATOR:
		Scale = 1.0f;
		break;
	}

	float HalfLength = mLength / 2.0f;
	Scale = lcMin(Scale, HalfLength);

	switch (mType)
	{
	default:
		ControlPoints[0].Transform = lcMatrix44Translation(lcVector3(-HalfLength, 0.0f, 0.0f));
		ControlPoints[1].Transform = lcMatrix44Translation(lcVector3( HalfLength, 0.0f, 0.0f));
		break;

	case lcSynthType::FLEX_SYSTEM_HOSE:
		ControlPoints[0].Transform = lcMatrix44Translation(lcVector3(0.0f, 0.0f, -mLength));
		ControlPoints[1].Transform = lcMatrix44Translation(lcVector3(0.0f, 0.0f, 0.0f));
		break;

	case lcSynthType::SHOCK_ABSORBER:
		ControlPoints[0].Transform = lcMatrix44Translation(lcVector3(0.0f, 0.0f, -mLength));
		ControlPoints[1].Transform = lcMatrix44Translation(lcVector3(0.0f, 0.0f, 0.0f));
		break;

	case lcSynthType::ACTUATOR:
		ControlPoints[0].Transform = lcMatrix44(lcMatrix33(lcVector3(1.0f, 0.0f, 0.0f), lcVector3(0.0f, 0.0f, -1.0f), lcVector3(0.0f, 1.0f, 0.0f)), lcVector3(0.0f, 0.0f, 0.0f));
		ControlPoints[1].Transform = lcMatrix44(lcMatrix33(lcVector3(1.0f, 0.0f, 0.0f), lcVector3(0.0f, 0.0f, -1.0f), lcVector3(0.0f, 1.0f, 0.0f)), lcVector3(0.0f, mLength, 0.0f));
		break;
	}

	ControlPoints[0].Scale = Scale;
	ControlPoints[1].Scale = Scale;
}

float lcSynthInfo::GetSectionTwist(const lcMatrix44& StartTransform, const lcMatrix44& EndTransform) const
{
	lcVector3 StartTangent(StartTransform[1].x, StartTransform[1].y, StartTransform[1].z);
	lcVector3 EndTangent(EndTransform[1].x, EndTransform[1].y, EndTransform[1].z);
	lcVector3 StartUp(StartTransform[2].x, StartTransform[2].y, StartTransform[2].z);
	lcVector3 EndUp(EndTransform[2].x, EndTransform[2].y, EndTransform[2].z);

	float TangentDot = lcDot(StartTangent, EndTangent);
	float UpDot = lcDot(StartUp, EndUp);

	if (TangentDot > 0.99f && UpDot > 0.99f)
		return 0.0f;

	if (fabs(TangentDot) > 0.99f)
	{
		return acosf(lcClamp(lcDot(EndUp, StartUp), -1.0f, 1.0f));
	}
	else if (TangentDot > -0.99f)
	{
		lcVector3 Axis = lcCross(StartTangent, EndTangent);
		float Angle = acosf(lcClamp(TangentDot, -1.0f, 1.0f));

		lcMatrix33 Rotation = lcMatrix33FromAxisAngle(Axis, Angle);
		lcVector3 AdjustedStartUp = lcMul(StartUp, Rotation);
		return acosf(lcClamp(lcDot(EndUp, AdjustedStartUp), -1.0f, 1.0f));
	}

	lcVector3 StartSide(StartTransform[0].x, StartTransform[0].y, StartTransform[0].z);
	lcVector3 EndSide(EndTransform[0].x, EndTransform[0].y, EndTransform[0].z);

	float SideDot = lcDot(StartSide, EndSide);

	if (fabs(SideDot) < 0.99f)
	{
		lcVector3 Axis = lcCross(StartSide, EndSide);
		float Angle = acosf(SideDot);

		lcMatrix33 Rotation = lcMatrix33FromAxisAngle(Axis, Angle);
		lcVector3 AdjustedStartUp = lcMul(StartUp, Rotation);
		return acosf(lcClamp(lcDot(EndUp, AdjustedStartUp), -1.0f, 1.0f));
	}

	return 0.0f;
}

void lcSynthInfo::CalculateCurveSections(const lcArray<lcPieceControlPoint>& ControlPoints, lcArray<lcMatrix44>& Sections, SectionCallbackFunc SectionCallback) const
{
	float SectionLength = 0.0f;

	for (int ControlPointIdx = 0; ControlPointIdx < ControlPoints.GetSize() - 1 && Sections.GetSize() < mNumSections + 2; ControlPointIdx++)
	{
		lcVector3 SegmentControlPoints[4];

		lcMatrix44 StartTransform = lcMatrix44LeoCADToLDraw(ControlPoints[ControlPointIdx].Transform);
		lcMatrix44 EndTransform = lcMatrix44LeoCADToLDraw(ControlPoints[ControlPointIdx + 1].Transform);
		StartTransform = lcMatrix44(lcMul(lcMul(lcMatrix33(mStart.Transform), lcMatrix33(StartTransform)), lcMatrix33Scale(lcVector3(1.0f, -1.0f, 1.0f))), StartTransform.GetTranslation());

		if (ControlPointIdx == 0)
		{
			if (mRigidEdges)
			{
				switch (mType)
				{
				default:
					StartTransform.SetTranslation(lcMul30(lcVector3(0.0f, mStart.Length, 0.0f), StartTransform) + StartTransform.GetTranslation());
					break;

				case lcSynthType::STRING_BRAIDED:
					StartTransform.SetTranslation(lcMul30(lcVector3(mStart.Length, 0.0f, 0.0f), StartTransform) + StartTransform.GetTranslation());
					break;
				}
				SectionLength = 0.0f;
			}
			else
				SectionLength = mStart.Length;

			Sections.Add(StartTransform);
		}

		EndTransform = lcMatrix44(lcMul(lcMul(lcMatrix33(mEnd.Transform), lcMatrix33(EndTransform)), lcMatrix33Scale(lcVector3(1.0f, -1.0f, 1.0f))), EndTransform.GetTranslation());

		SegmentControlPoints[0] = StartTransform.GetTranslation();
		switch (mType)
		{
		default:
			SegmentControlPoints[1] = lcMul31(lcVector3(0.0f, ControlPoints[ControlPointIdx].Scale, 0.0f), StartTransform);
			SegmentControlPoints[2] = lcMul31(lcVector3(0.0f, -ControlPoints[ControlPointIdx + 1].Scale, 0.0f), EndTransform);
			break;

		case lcSynthType::STRING_BRAIDED:
			SegmentControlPoints[1] = lcMul31(lcVector3(ControlPoints[ControlPointIdx].Scale, 0.0f, 0.0f), StartTransform);
			SegmentControlPoints[2] = lcMul31(lcVector3(-ControlPoints[ControlPointIdx + 1].Scale, 0.0f, 0.0f), EndTransform);
			break;
		}
		SegmentControlPoints[3] = EndTransform.GetTranslation();

		const int NumCurvePoints = 8192;
		lcArray<lcVector3> CurvePoints;
		CurvePoints.AllocGrow(NumCurvePoints);

		for (int PointIdx = 0; PointIdx < NumCurvePoints; PointIdx++)
		{
			float t = (float)PointIdx / (float)(NumCurvePoints - 1);
			float it = 1.0f - t;

			lcVector3 Position = it * it * it * SegmentControlPoints[0] + it * it * 3.0f * t * SegmentControlPoints[1] + it * 3.0 * t * t * SegmentControlPoints[2] + t * t * t * SegmentControlPoints[3];
			CurvePoints.Add(Position);
		}

		float CurrentSegmentLength = 0.0f;
		float TotalSegmentLength = 0.0f;

		for (int PointIdx = 0; PointIdx < CurvePoints.GetSize() - 1; PointIdx++)
			TotalSegmentLength += lcLength(CurvePoints[PointIdx] - CurvePoints[PointIdx + 1]);

		lcVector3 StartUp;
		if (mType != lcSynthType::STRING_BRAIDED)
			StartUp = lcMul30(lcVector3(1.0f, 0.0f, 0.0f), StartTransform);
		else
			StartUp = lcMul30(lcVector3(0.0f, 1.0f, 0.0f), StartTransform);
		float Twist = GetSectionTwist(StartTransform, EndTransform);
		int CurrentPointIndex = 0;

		while (CurrentPointIndex < CurvePoints.GetSize() - 1)
		{
			float Length = lcLength(CurvePoints[CurrentPointIndex + 1] - CurvePoints[CurrentPointIndex]);
			CurrentSegmentLength += Length;
			SectionLength -= Length;
			CurrentPointIndex++;

			if (SectionLength > 0.0f)
				continue;

			float t = (float)CurrentPointIndex / (float)(NumCurvePoints - 1);
			float it = 1.0f - t;

			lcVector3 Tangent = lcNormalize(-3.0f * it * it * SegmentControlPoints[0] + (3.0f * it * it - 6.0f * t * it) * SegmentControlPoints[1] + (-3.0f * t * t + 6.0f * t * it) * SegmentControlPoints[2] + 3.0f * t * t * SegmentControlPoints[3]);
			lcVector3 Up;

			if (Twist)
			{
				Up = lcMul(StartUp, lcMatrix33FromAxisAngle(Tangent, Twist * (CurrentSegmentLength / TotalSegmentLength)));
				CurrentSegmentLength = 0.0f;
			}
			else
				Up = StartUp;

			lcVector3 Side = lcNormalize(lcCross(Tangent, Up));
			Up = lcNormalize(lcCross(Side, Tangent));
			StartUp = Up;

			if (mType != lcSynthType::STRING_BRAIDED)
				Sections.Add(lcMatrix44(lcMatrix33(Up, Tangent, Side), CurvePoints[CurrentPointIndex]));
			else
				Sections.Add(lcMatrix44(lcMatrix33(Tangent, Up, -Side), CurvePoints[CurrentPointIndex]));

			if (SectionCallback)
				SectionCallback(CurvePoints[CurrentPointIndex], ControlPointIdx, t);

			if (Sections.GetSize() == mNumSections + 2)
				break;

			if (mCenterLength != 0.0f && (Sections.GetSize() == mNumSections / 2 + 1))
				SectionLength += mCenterLength;
			else
				SectionLength += mMiddle.Length;

			if (Sections.GetSize() == mNumSections + 1 && !mRigidEdges)
				SectionLength += mEnd.Length;
		}
	}

	while (Sections.GetSize() < mNumSections + 2)
	{
		lcMatrix44 EndTransform = lcMatrix44LeoCADToLDraw(ControlPoints[ControlPoints.GetSize() - 1].Transform);
		EndTransform = lcMatrix44(lcMul(lcMul(lcMatrix33(mEnd.Transform), lcMatrix33(EndTransform)), lcMatrix33Scale(lcVector3(1.0f, -1.0f, 1.0f))), EndTransform.GetTranslation());
		lcVector3 Position;
		if (mType != lcSynthType::STRING_BRAIDED)
			Position = lcMul31(lcVector3(0.0f, SectionLength, 0.0f), EndTransform);
		else
			Position = lcMul31(lcVector3(SectionLength, 0.0f, 0.0f), EndTransform);
		EndTransform.SetTranslation(Position);
		Sections.Add(EndTransform);

		if (SectionCallback)
			SectionCallback(Position, ControlPoints.GetSize() - 1, 1.0f);

		if (mCenterLength != 0.0f && (Sections.GetSize() == mNumSections / 2 + 1))
			SectionLength += mCenterLength;
		else
			SectionLength += mMiddle.Length;

		if (Sections.GetSize() == mNumSections + 1 && !mRigidEdges)
			SectionLength += mEnd.Length;
	}
}

void lcSynthInfo::CalculateLineSections(const lcArray<lcPieceControlPoint>& ControlPoints, lcArray<lcMatrix44>& Sections, SectionCallbackFunc SectionCallback) const
{
	for (int ControlPointIdx = 0; ControlPointIdx < ControlPoints.GetSize(); ControlPointIdx++)
	{
		lcMatrix44 Transform = lcMatrix44LeoCADToLDraw(ControlPoints[ControlPointIdx].Transform);
		Sections.Add(Transform);

		if (SectionCallback)
			SectionCallback(Transform.GetTranslation(), ControlPointIdx, 1.0f);
	}
}

void lcSynthInfo::AddHoseFlexibleParts(lcMemFile& File, const lcArray<lcMatrix44>& Sections) const
{
	char Line[256];
	const int NumEdgeParts = 2;

	const lcMatrix33 EdgeTransforms[2] =
	{
		lcMatrix33(lcVector3(0.0f, 0.0f, -1.0f), lcVector3(0.0f, -1.0f, 0.0f), lcVector3(1.0f, 0.0f, 0.0f)),
		lcMatrix33(lcVector3(0.0f, 0.0f, -1.0f), lcVector3(0.0f,  1.0f, 0.0f), lcVector3(1.0f, 0.0f, 0.0f))
	};

	const char* EdgePartsA[2] =
	{
		"755.dat", "752.dat"
	};

	const char* EdgePartsB[2] =
	{
		"755.dat", "750.dat"
	};

	const char** EdgeParts = !strcmp(mPieceInfo->mFileName, "73590a.dat") ? EdgePartsA : EdgePartsB;

	for (int PartIdx = 0; PartIdx < NumEdgeParts; PartIdx++)
	{
		const int SectionIdx = 0;
		lcMatrix33 Transform(lcMul(lcMul(EdgeTransforms[PartIdx], lcMatrix33Scale(lcVector3(1.0f, -1.0f, 1.0f))), lcMatrix33(Sections[SectionIdx])));
		lcVector3 Offset = lcMul31(lcVector3(0.0f, -5.0f, 0.0f), Sections[SectionIdx]);

		sprintf(Line, "1 16 %f %f %f %f %f %f %f %f %f %f %f %f %s\n", Offset[0], Offset[1], Offset[2], Transform[0][0], Transform[1][0], Transform[2][0],
		        Transform[0][1], Transform[1][1], Transform[2][1], Transform[0][2], Transform[1][2], Transform[2][2], EdgeParts[PartIdx]);

		File.WriteBuffer(Line, strlen(Line));
	}

	for (int SectionIdx = 1; SectionIdx < Sections.GetSize() - 1; SectionIdx++)
	{
		lcMatrix33 Transform = lcMatrix33(Sections[SectionIdx]);
		lcVector3 Offset = Sections[SectionIdx].GetTranslation();

		if (SectionIdx < Sections.GetSize() / 2)
			Transform = lcMul(lcMatrix33(lcVector3(0.0f, 0.0f, -1.0f), lcVector3(0.0f, -1.0f, 0.0f), lcVector3(-1.0f, 0.0f, 0.0f)), Transform);
		else if (SectionIdx != Sections.GetSize() / 2)
			Transform = lcMul(lcMatrix33(lcVector3(0.0f, 0.0f, -1.0f), lcVector3(0.0f,  1.0f, 0.0f), lcVector3( 1.0f, 0.0f, 0.0f)), Transform);
		else
			Transform = lcMul(lcMatrix33(lcVector3(0.0f, 0.0f, -1.0f), lcVector3(0.0f,  1.0f, 0.0f), lcVector3( 1.0f, 0.0f, 0.0f)), Transform);

		const char* Part = SectionIdx != Sections.GetSize() / 2 ? "754.dat" : "756.dat";

		sprintf(Line, "1 16 %f %f %f %f %f %f %f %f %f %f %f %f %s\n", Offset[0], Offset[1], Offset[2], Transform[0][0], Transform[1][0], Transform[2][0],
		        Transform[0][1], Transform[1][1], Transform[2][1], Transform[0][2], Transform[1][2], Transform[2][2], Part);

		File.WriteBuffer(Line, strlen(Line));
	}

	for (int PartIdx = 0; PartIdx < NumEdgeParts; PartIdx++)
	{
		const int SectionIdx = Sections.GetSize() - 1;
		lcMatrix33 Transform(lcMul(EdgeTransforms[PartIdx], lcMatrix33(Sections[SectionIdx])));
		lcVector3 Offset = lcMul31(lcVector3(0.0f, 5.0f - 2.56f, 0.0f), Sections[SectionIdx]);

		sprintf(Line, "1 16 %f %f %f %f %f %f %f %f %f %f %f %f %s\n", Offset[0], Offset[1], Offset[2], Transform[0][0], Transform[1][0], Transform[2][0],
		        Transform[0][1], Transform[1][1], Transform[2][1], Transform[0][2], Transform[1][2], Transform[2][2], EdgeParts[PartIdx]);

		File.WriteBuffer(Line, strlen(Line));
	}
}

void lcSynthInfo::AddFlexHoseParts(lcMemFile& File, lcLibraryMeshData& MeshData, const lcArray<lcMatrix44>& Sections) const
{
	char Line[256];

	{
		const int SectionIdx = 0;
		lcMatrix33 Transform(lcMul(lcMatrix33Scale(lcVector3(-1.0f, 1.0f, 1.0f)), lcMatrix33(Sections[SectionIdx])));
		lcVector3 Offset = lcMul31(lcVector3(0.0f, -1.0f, 0.0f), Sections[SectionIdx]);

		sprintf(Line, "1 16 %f %f %f %f %f %f %f %f %f %f %f %f u9053.dat\n", Offset[0], Offset[1], Offset[2], Transform[0][0], Transform[1][0], Transform[2][0],
				Transform[0][1], Transform[1][1], Transform[2][1], Transform[0][2], Transform[1][2], Transform[2][2]);

		File.WriteBuffer(Line, strlen(Line));
	}

	{
		const int SectionIdx = Sections.GetSize() - 1;
		lcMatrix33 Transform(lcMul(lcMatrix33Scale(lcVector3(1.0f, -1.0f, 1.0f)), lcMatrix33(Sections[SectionIdx])));
		lcVector3 Offset = lcMul31(lcVector3(0.0f, 1.0f, 0.0f), Sections[SectionIdx]);

		sprintf(Line, "1 16 %f %f %f %f %f %f %f %f %f %f %f %f u9053.dat\n", Offset[0], Offset[1], Offset[2], Transform[0][0], Transform[1][0], Transform[2][0],
				Transform[0][1], Transform[1][1], Transform[2][1], Transform[0][2], Transform[1][2], Transform[2][2]);

		File.WriteBuffer(Line, strlen(Line));
	}

	const lcLibraryMeshVertex OutsideSectionVertices[16] =
	{
		{ lcVector3( 4.00000f, 0.0f,  0.00000f), lcVector3( 1.000000f, 0.0f,  0.000000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 3.69552f, 0.0f,  1.53073f), lcVector3( 0.923880f, 0.0f,  0.382683f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 2.82843f, 0.0f,  2.82843f), lcVector3( 0.707107f, 0.0f,  0.707107f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 1.53073f, 0.0f,  3.69552f), lcVector3( 0.382683f, 0.0f,  0.923880f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 0.00000f, 0.0f,  4.00000f), lcVector3( 0.000000f, 0.0f,  1.000000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-1.53073f, 0.0f,  3.69552f), lcVector3(-0.382683f, 0.0f,  0.923880f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-2.82843f, 0.0f,  2.82843f), lcVector3(-0.707107f, 0.0f,  0.707107f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-3.69552f, 0.0f,  1.53073f), lcVector3(-0.923880f, 0.0f,  0.382683f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-4.00000f, 0.0f,  0.00000f), lcVector3(-1.000000f, 0.0f,  0.000000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-3.69552f, 0.0f, -1.53073f), lcVector3(-0.923879f, 0.0f, -0.382684f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-2.82843f, 0.0f, -2.82843f), lcVector3(-0.707107f, 0.0f, -0.707107f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-1.53073f, 0.0f, -3.69552f), lcVector3(-0.382683f, 0.0f, -0.923880f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 0.00000f, 0.0f, -4.00000f), lcVector3( 0.000000f, 0.0f, -1.000000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 1.53073f, 0.0f, -3.69552f), lcVector3( 0.382684f, 0.0f, -0.923879f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 2.82843f, 0.0f, -2.82843f), lcVector3( 0.707107f, 0.0f, -0.707107f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 3.69552f, 0.0f, -1.53073f), lcVector3( 0.923880f, 0.0f, -0.382683f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
	};

	const lcLibraryMeshVertex InsideSectionVertices[16] =
	{
		{ lcVector3( 2.00000f, 0.0f,  0.00000f), lcVector3(-1.00000f, 0.0f,  0.00000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 1.84776f, 0.0f,  0.76536f), lcVector3(-0.92388f, 0.0f, -0.38268f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 1.41421f, 0.0f,  1.41421f), lcVector3(-0.70710f, 0.0f, -0.70710f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 0.76536f, 0.0f,  1.84776f), lcVector3(-0.38268f, 0.0f, -0.92388f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 0.00000f, 0.0f,  2.00000f), lcVector3( 0.00000f, 0.0f, -1.00000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-0.76536f, 0.0f,  1.84776f), lcVector3( 0.38268f, 0.0f, -0.92388f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-1.41421f, 0.0f,  1.41421f), lcVector3( 0.70710f, 0.0f, -0.70710f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-1.84776f, 0.0f,  0.76536f), lcVector3( 0.92388f, 0.0f, -0.38268f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-2.00000f, 0.0f,  0.00000f), lcVector3( 1.00000f, 0.0f,  0.00000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-1.84776f, 0.0f, -0.76536f), lcVector3( 0.92387f, 0.0f,  0.38268f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-1.41421f, 0.0f, -1.41421f), lcVector3( 0.70710f, 0.0f,  0.70710f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-0.76536f, 0.0f, -1.84776f), lcVector3( 0.38268f, 0.0f,  0.92388f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 0.00000f, 0.0f, -2.00000f), lcVector3( 0.00000f, 0.0f,  1.00000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 0.76536f, 0.0f, -1.84776f), lcVector3(-0.38268f, 0.0f,  0.92387f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 1.41421f, 0.0f, -1.41421f), lcVector3(-0.70710f, 0.0f,  0.70710f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 1.84776f, 0.0f, -0.76536f), lcVector3(-0.92388f, 0.0f,  0.38268f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
	};

	auto AddSectionVertices = [&MeshData, &Sections](const lcLibraryMeshVertex* SectionVertices, int NumSectionVertices)
	{
		int BaseVertex;
		lcLibraryMeshVertex* VertexBuffer;
		quint32* IndexBuffer;
		MeshData.AddVertices(LC_MESHDATA_SHARED, NumSectionVertices * (Sections.GetSize() - 1), &BaseVertex, &VertexBuffer);

		for (int SectionIdx = 1; SectionIdx < Sections.GetSize(); SectionIdx++)
		{
			for (int VertexIdx = 0; VertexIdx < NumSectionVertices; VertexIdx++)
			{
				VertexBuffer->Position = lcMul31(SectionVertices[VertexIdx].Position, Sections[SectionIdx]);
				VertexBuffer->Normal = lcMul30(SectionVertices[VertexIdx].Normal, Sections[SectionIdx]);
				VertexBuffer->NormalWeight = SectionVertices[VertexIdx].NormalWeight;
				VertexBuffer++;
			}
		}

		MeshData.AddIndices(LC_MESHDATA_SHARED, LC_MESH_TRIANGLES, 16, 6 * NumSectionVertices * (Sections.GetSize() - 2), &IndexBuffer);

		for (int SectionIdx = 1; SectionIdx < Sections.GetSize() - 1; SectionIdx++)
		{
			for (int VertexIdx = 0; VertexIdx < NumSectionVertices; VertexIdx++)
			{
				int Vertex1 = BaseVertex + VertexIdx;
				int Vertex2 = BaseVertex + (VertexIdx + 1) % NumSectionVertices;

				*IndexBuffer++ = Vertex1;
				*IndexBuffer++ = Vertex2;
				*IndexBuffer++ = Vertex1 + NumSectionVertices;
				*IndexBuffer++ = Vertex2;
				*IndexBuffer++ = Vertex2 + NumSectionVertices;
				*IndexBuffer++ = Vertex1 + NumSectionVertices;
			}
			BaseVertex += NumSectionVertices;
		}
	};

	AddSectionVertices(OutsideSectionVertices, sizeof(OutsideSectionVertices) / sizeof(OutsideSectionVertices[0]));
	AddSectionVertices(InsideSectionVertices, sizeof(InsideSectionVertices) / sizeof(InsideSectionVertices[0]));
}

void lcSynthInfo::AddRibbedHoseParts(lcMemFile& File, const lcArray<lcMatrix44>& Sections) const
{
	char Line[256];

	{
		const int SectionIdx = 0;
		lcMatrix33 Transform(lcMul(lcMatrix33Scale(lcVector3(1.0f, -1.0f, 1.0f)), lcMatrix33(Sections[SectionIdx])));
		lcVector3 Offset = Sections[SectionIdx].GetTranslation();

		sprintf(Line, "1 16 %f %f %f %f %f %f %f %f %f %f %f %f 79.dat\n", Offset[0], Offset[1], Offset[2], Transform[0][0], Transform[1][0], Transform[2][0],
				Transform[0][1], Transform[1][1], Transform[2][1], Transform[0][2], Transform[1][2], Transform[2][2]);

		File.WriteBuffer(Line, strlen(Line));
	}

	for (int SectionIdx = 1; SectionIdx < Sections.GetSize() - 1; SectionIdx++)
	{
		const lcMatrix44& Transform = Sections[SectionIdx];

		sprintf(Line, "1 16 %f %f %f %f %f %f %f %f %f %f %f %f 80.dat\n", Transform[3][0], Transform[3][1], Transform[3][2], Transform[0][0], Transform[1][0], Transform[2][0],
				Transform[0][1], Transform[1][1], Transform[2][1], Transform[0][2], Transform[1][2], Transform[2][2]);

		File.WriteBuffer(Line, strlen(Line));
	}

	{
		const int SectionIdx = Sections.GetSize() - 1;
		lcMatrix33 Transform(Sections[SectionIdx]);
		lcVector3 Offset = lcMul31(lcVector3(0.0f, -6.25f, 0.0f), Sections[SectionIdx]);

		sprintf(Line, "1 16 %f %f %f %f %f %f %f %f %f %f %f %f 79.dat\n", Offset[0], Offset[1], Offset[2], Transform[0][0], Transform[1][0], Transform[2][0],
				Transform[0][1], Transform[1][1], Transform[2][1], Transform[0][2], Transform[1][2], Transform[2][2]);

		File.WriteBuffer(Line, strlen(Line));
	}
}

void lcSynthInfo::AddFlexibleAxleParts(lcMemFile& File, lcLibraryMeshData& MeshData, const lcArray<lcMatrix44>& Sections) const
{
	char Line[256];
	const int NumEdgeParts = 6;

	lcMatrix33 EdgeTransforms[6] = 
	{
		lcMatrix33(lcVector3(-1.0f, 0.0f, 0.0f), lcVector3(0.0f, -5.0f, 0.0f), lcVector3(0.0f, 0.0f,  1.0f)),
		lcMatrix33(lcVector3( 0.0f, 1.0f, 0.0f), lcVector3(1.0f,  0.0f, 0.0f), lcVector3(0.0f, 0.0f, -1.0f)),
		lcMatrix33(lcVector3( 0.0f, 1.0f, 0.0f), lcVector3(1.0f,  0.0f, 0.0f), lcVector3(0.0f, 0.0f, -1.0f)),
		lcMatrix33(lcVector3( 0.0f, 1.0f, 0.0f), lcVector3(1.0f,  0.0f, 0.0f), lcVector3(0.0f, 0.0f, -1.0f)),
		lcMatrix33(lcVector3( 0.0f, 1.0f, 0.0f), lcVector3(1.0f,  0.0f, 0.0f), lcVector3(0.0f, 0.0f, -1.0f)),
		lcMatrix33(lcVector3( 0.0f, 1.0f, 0.0f), lcVector3(1.0f,  0.0f, 0.0f), lcVector3(0.0f, 0.0f, -1.0f)),
	};

	const char* EdgeParts[6] =
	{
		"stud3a.dat", "s/faxle1.dat", "s/faxle2.dat", "s/faxle3.dat", "s/faxle4.dat", "s/faxle5.dat"
	};

	for (int PartIdx = 0; PartIdx < NumEdgeParts; PartIdx++)
	{
		const int SectionIdx = 0;
		lcMatrix33 Transform(lcMul(lcMul(EdgeTransforms[PartIdx], lcMatrix33Scale(lcVector3(1.0f, -1.0f, 1.0f))), lcMatrix33(Sections[SectionIdx])));
		lcVector3 Offset = lcMul31(lcVector3(0.0f, -4.0f * (5 - PartIdx), 0.0f), Sections[SectionIdx]);

		sprintf(Line, "1 16 %f %f %f %f %f %f %f %f %f %f %f %f %s\n", Offset[0], Offset[1], Offset[2], Transform[0][0], Transform[1][0], Transform[2][0],
				Transform[0][1], Transform[1][1], Transform[2][1], Transform[0][2], Transform[1][2], Transform[2][2], EdgeParts[PartIdx]);

		File.WriteBuffer(Line, strlen(Line));
	}

	for (int PartIdx = 0; PartIdx < NumEdgeParts; PartIdx++)
	{
		const int SectionIdx = Sections.GetSize() - 1;
		lcMatrix33 Transform(lcMul(EdgeTransforms[PartIdx], lcMatrix33(Sections[SectionIdx])));
		lcVector3 Offset = lcMul31(lcVector3(0.0f, 4.0f * (5 - PartIdx), 0.0f), Sections[SectionIdx]);

		sprintf(Line, "1 16 %f %f %f %f %f %f %f %f %f %f %f %f %s\n", Offset[0], Offset[1], Offset[2], Transform[0][0], Transform[1][0], Transform[2][0],
				Transform[0][1], Transform[1][1], Transform[2][1], Transform[0][2], Transform[1][2], Transform[2][2], EdgeParts[PartIdx]);

		File.WriteBuffer(Line, strlen(Line));
	}

	const lcLibraryMeshVertex SectionVertices[28] =
	{
		{ lcVector3(-6.000f, 0.0f,  0.000f), lcVector3(-1.000f, 0.0f,  0.000f), 2.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-5.602f, 0.0f,  2.000f), lcVector3(-0.942f, 0.0f,  0.336f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-5.602f, 0.0f,  2.000f), lcVector3( 0.000f, 0.0f,  1.000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-2.000f, 0.0f,  2.000f), lcVector3( 0.000f, 0.0f,  1.000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-2.000f, 0.0f,  2.000f), lcVector3(-1.000f, 0.0f,  0.000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-2.000f, 0.0f,  5.602f), lcVector3(-1.000f, 0.0f,  0.000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-2.000f, 0.0f,  5.602f), lcVector3(-0.336f, 0.0f,  0.942f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 0.000f, 0.0f,  6.000f), lcVector3( 0.000f, 0.0f,  1.000f), 2.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 2.000f, 0.0f,  5.602f), lcVector3( 0.336f, 0.0f,  0.942f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 2.000f, 0.0f,  5.602f), lcVector3( 1.000f, 0.0f,  0.000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 2.000f, 0.0f,  2.000f), lcVector3( 1.000f, 0.0f,  0.000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 2.000f, 0.0f,  2.000f), lcVector3( 0.000f, 0.0f,  1.000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 5.602f, 0.0f,  2.000f), lcVector3( 0.000f, 0.0f,  1.000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 5.602f, 0.0f,  2.000f), lcVector3( 0.942f, 0.0f,  0.336f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 6.000f, 0.0f,  0.000f), lcVector3( 1.000f, 0.0f,  0.000f), 2.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 5.602f, 0.0f, -2.000f), lcVector3( 0.942f, 0.0f, -0.336f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 5.602f, 0.0f, -2.000f), lcVector3( 0.000f, 0.0f, -1.000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 2.000f, 0.0f, -2.000f), lcVector3( 0.000f, 0.0f, -1.000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 2.000f, 0.0f, -2.000f), lcVector3( 1.000f, 0.0f,  0.000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 2.000f, 0.0f, -5.602f), lcVector3( 1.000f, 0.0f,  0.000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 2.000f, 0.0f, -5.602f), lcVector3( 0.336f, 0.0f, -0.942f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3( 0.000f, 0.0f, -6.000f), lcVector3( 0.000f, 0.0f, -1.000f), 2.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-2.000f, 0.0f, -5.602f), lcVector3(-0.336f, 0.0f, -0.942f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-2.000f, 0.0f, -5.602f), lcVector3(-1.000f, 0.0f,  0.000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-2.000f, 0.0f, -2.000f), lcVector3(-1.000f, 0.0f,  0.000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-2.000f, 0.0f, -2.000f), lcVector3( 0.000f, 0.0f, -1.000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-5.602f, 0.0f, -2.000f), lcVector3( 0.000f, 0.0f, -1.000f), 4.0f, lcVector2(0.0f, 0.0f), 0 },
		{ lcVector3(-5.602f, 0.0f, -2.000f), lcVector3(-0.942f, 0.0f, -0.336f), 4.0f, lcVector2(0.0f, 0.0f), 0 }
	};

	const int NumSectionVertices = sizeof(SectionVertices) / sizeof(SectionVertices[0]);

	int BaseVertex;
	lcLibraryMeshVertex* VertexBuffer;
	quint32* IndexBuffer;
	MeshData.AddVertices(LC_MESHDATA_SHARED, NumSectionVertices * (Sections.GetSize() - 1), &BaseVertex, &VertexBuffer);
	MeshData.AddIndices(LC_MESHDATA_SHARED, LC_MESH_LINES, 24, 2 * 12 * (Sections.GetSize() - 2), &IndexBuffer);

	for (int SectionIdx = 1; SectionIdx < Sections.GetSize(); SectionIdx++)
	{
		for (int VertexIdx = 0; VertexIdx < NumSectionVertices; VertexIdx++)
		{
			VertexBuffer->Position = lcMul31(SectionVertices[VertexIdx].Position, Sections[SectionIdx]);
			VertexBuffer->Normal = lcMul30(SectionVertices[VertexIdx].Normal, Sections[SectionIdx]);
			VertexBuffer->NormalWeight = SectionVertices[VertexIdx].NormalWeight;
			VertexBuffer++;
		}
	}

	int BaseLinesVertex = BaseVertex;

	for (int SectionIdx = 1; SectionIdx < Sections.GetSize() - 1; SectionIdx++)
	{
		const int Indices[] = { 1, 3, 5, 8, 10, 12, 15, 17, 19, 22, 24, 26 };
	
		for (int VertexIdx = 0; VertexIdx < 12; VertexIdx++)
		{
			*IndexBuffer++ = BaseLinesVertex + Indices[VertexIdx];
			*IndexBuffer++ = BaseLinesVertex + Indices[VertexIdx] + NumSectionVertices;
		}

		BaseLinesVertex += NumSectionVertices;
	}

	MeshData.AddIndices(LC_MESHDATA_SHARED, LC_MESH_TRIANGLES, 16, 6 * NumSectionVertices * (Sections.GetSize() - 2), &IndexBuffer);

	for (int SectionIdx = 1; SectionIdx < Sections.GetSize() - 1; SectionIdx++)
	{
		for (int VertexIdx = 0; VertexIdx < NumSectionVertices; VertexIdx++)
		{
			int Vertex1 = BaseVertex + VertexIdx;
			int Vertex2 = BaseVertex + (VertexIdx + 1) % NumSectionVertices;

			*IndexBuffer++ = Vertex1;
			*IndexBuffer++ = Vertex2;
			*IndexBuffer++ = Vertex1 + NumSectionVertices;
			*IndexBuffer++ = Vertex2;
			*IndexBuffer++ = Vertex2 + NumSectionVertices;
			*IndexBuffer++ = Vertex1 + NumSectionVertices;
		}
		BaseVertex += NumSectionVertices;
	}
}

void lcSynthInfo::AddStringBraidedParts(lcMemFile& File, lcLibraryMeshData& MeshData, lcArray<lcMatrix44>& Sections) const
{
	for (int SectionIdx = 0; SectionIdx < Sections.GetSize(); SectionIdx++)
	{
		lcMatrix33 Transform(lcMul(lcMatrix33Scale(lcVector3(1.0f, -1.0f, 1.0f)), lcMatrix33(Sections[SectionIdx])));
		lcVector3 Offset = Sections[SectionIdx].GetTranslation();
		Sections[SectionIdx] = lcMatrix44(Transform, Offset);
	}

	char Line[256];

	{
		const int SectionIdx = 0;
		lcMatrix33 Transform(Sections[SectionIdx]);
		lcVector3 Offset = lcMul31(lcVector3(-8.0f, 0.0f, 0.0f), Sections[SectionIdx]);

		sprintf(Line, "1 16 %f %f %f %f %f %f %f %f %f %f %f %f 572A.dat\n", Offset[0], Offset[1], Offset[2], Transform[0][0], Transform[1][0], Transform[2][0],
				Transform[0][1], Transform[1][1], Transform[2][1], Transform[0][2], Transform[1][2], Transform[2][2]);

		File.WriteBuffer(Line, strlen(Line));
	}

	const int NumSegments = 16;
	const int NumBraids = 4;
	const float PositionTable[16] =
	{
		-1.5f, -1.386f, -1.061f, -0.574f, 0.0f, 0.574f, 1.061f, 1.386f, 1.5f, 1.386f, 1.061f, 0.574f, 0.0f, -0.574f, -1.061f, -1.386f
	};

	int BaseVertex;
	lcLibraryMeshVertex* VertexBuffer;
	quint32* IndexBuffer;
	MeshData.AddVertices(LC_MESHDATA_SHARED, NumBraids * ((Sections.GetSize() - 2) * NumSegments + 1), &BaseVertex, &VertexBuffer);
	MeshData.AddIndices(LC_MESHDATA_SHARED, LC_MESH_LINES, 24, NumBraids * (Sections.GetSize() - 2) * NumSegments * 2, &IndexBuffer);

	for (int BraidIdx = 0; BraidIdx < NumBraids; BraidIdx++)
	{
		int BaseX = (BraidIdx == 0 || BraidIdx == 2) ? 0 : 8;
		int BaseY = (BraidIdx == 0 || BraidIdx == 3) ? 12 : 4;

		for (int SectionIdx = 1; SectionIdx < Sections.GetSize() - 1; SectionIdx++)
		{
			lcMatrix33 Transform1 = lcMatrix33(Sections[SectionIdx]);
			lcMatrix33 Transform2 = lcMatrix33(Sections[SectionIdx + 1]);
			lcVector3 Offset1 = Sections[SectionIdx].GetTranslation();
			lcVector3 Offset2 = Sections[SectionIdx + 1].GetTranslation();

			for (int SegmentIdx = 0; SegmentIdx < ((SectionIdx < Sections.GetSize() - 2) ? NumSegments : NumSegments + 1); SegmentIdx++)
			{
				float t = (float)SegmentIdx / (float)NumSegments;

				lcVector3 Vertex1 = lcVector3(t * 4.0f, PositionTable[(BaseX + SegmentIdx) % NumSegments], PositionTable[(BaseY + SegmentIdx) % NumSegments]) + lcVector3(0.0f, 1.5f, 0.0f);
				lcVector3 Vertex2 = lcVector3((1.0f - t) * -4.0f, PositionTable[(BaseX + SegmentIdx) % NumSegments], PositionTable[(BaseY + SegmentIdx) % NumSegments]) + lcVector3(0.0f, 1.5f, 0.0f);

				lcVector3 Vertex = (lcMul(Vertex1, Transform1) + Offset1) * (1.0f - t) + (lcMul(Vertex2, Transform2) + Offset2) * t;

				VertexBuffer->Position = Vertex;
				VertexBuffer->Normal = lcVector3(0.0f, 0.0f, 0.0f);
				VertexBuffer->NormalWeight = 0.0f;
				VertexBuffer++;

				if (SegmentIdx != NumSegments)
				{
					*IndexBuffer++ = BaseVertex;
					*IndexBuffer++ = BaseVertex + 1;
					BaseVertex++;
				}
			}
		}

		BaseVertex++;
	}

	int NumSlices = 16;
	MeshData.AddVertices(LC_MESHDATA_SHARED, NumSlices * ((Sections.GetSize() - 2) * NumSegments + 1), &BaseVertex, &VertexBuffer);
	MeshData.AddIndices(LC_MESHDATA_SHARED, LC_MESH_TRIANGLES, 16, NumSlices * (Sections.GetSize() - 2) * NumSegments * 6, &IndexBuffer);

	for (int SectionIdx = 1; SectionIdx < Sections.GetSize() - 1; SectionIdx++)
	{
		lcMatrix33 Transform1 = lcMatrix33(Sections[SectionIdx]);
		lcMatrix33 Transform2 = lcMatrix33(Sections[SectionIdx + 1]);
		lcVector3 Offset1 = Sections[SectionIdx].GetTranslation();
		lcVector3 Offset2 = Sections[SectionIdx + 1].GetTranslation();

		for (int SegmentIdx = 0; SegmentIdx < ((SectionIdx < Sections.GetSize() - 2) ? NumSegments : NumSegments + 1); SegmentIdx++)
		{
			float t1 = (float)SegmentIdx / (float)NumSegments;
			int BaseX = 8;
			int BaseY = 4;

			for (int SliceIdx = 0; SliceIdx < NumSlices; SliceIdx++)
			{
				lcVector3 Vertex11 = lcVector3(t1 * 4.0f, PositionTable[(BaseX + SliceIdx) % NumSlices], PositionTable[(BaseY + SliceIdx) % NumSlices]) + lcVector3(0.0f, 1.5f, 0.0f);
				lcVector3 Vertex12 = lcVector3((1.0f - t1) * -4.0f, PositionTable[(BaseX + SliceIdx) % NumSlices], PositionTable[(BaseY + SliceIdx) % NumSlices]) + lcVector3(0.0f, 1.5f, 0.0f);
				VertexBuffer->Position = (lcMul(Vertex11, Transform1) + Offset1) * (1.0f - t1) + (lcMul(Vertex12, Transform2) + Offset2) * t1;

				lcVector3 Normal11 = lcVector3(0.0f, PositionTable[(BaseX + SliceIdx) % NumSlices] / 1.5f, PositionTable[(BaseY + SliceIdx) % NumSlices] / 1.5f);
				lcVector3 Normal12 = lcVector3(0.0f, PositionTable[(BaseX + SliceIdx) % NumSlices] / 1.5f, PositionTable[(BaseY + SliceIdx) % NumSlices] / 1.5f);
				VertexBuffer->Normal = lcMul(Normal11, Transform1) * (1.0f - t1) + lcMul(Normal12, Transform2) * t1;
				VertexBuffer->NormalWeight = 1.0f;
				VertexBuffer++;

				if (SegmentIdx != NumSegments)
				{
					*IndexBuffer++ = BaseVertex + SliceIdx;
					*IndexBuffer++ = BaseVertex + (SliceIdx + 1) % NumSlices;
					*IndexBuffer++ = BaseVertex + (SliceIdx + 1) % NumSlices + NumSlices;

					*IndexBuffer++ = BaseVertex + SliceIdx + NumSlices;
					*IndexBuffer++ = BaseVertex + SliceIdx;
					*IndexBuffer++ = BaseVertex + (SliceIdx + 1) % NumSlices + NumSlices;
				}
			}

			BaseVertex += NumSlices;
		}
	}

	{
		const int SectionIdx = Sections.GetSize() - 1;
		lcMatrix33 Transform(Sections[SectionIdx]);
		lcVector3 Offset = lcMul31(lcVector3(8.0f, 0.0f, 0.0f), Sections[SectionIdx]);

		sprintf(Line, "1 16 %f %f %f %f %f %f %f %f %f %f %f %f 572A.dat\n", Offset[0], Offset[1], Offset[2], Transform[0][0], Transform[1][0], Transform[2][0],
				Transform[0][1], Transform[1][1], Transform[2][1], Transform[0][2], Transform[1][2], Transform[2][2]);

		File.WriteBuffer(Line, strlen(Line));
	}
}

void lcSynthInfo::AddShockAbsorberParts(lcMemFile& File, lcArray<lcMatrix44>& Sections) const
{
	char Line[256];
	lcVector3 Offset;

	Offset = Sections[0].GetTranslation();
	sprintf(Line, "1 0 %f %f %f 1 0 0 0 1 0 0 0 1 4254.dat\n", Offset[0], Offset[1], Offset[2]);
	File.WriteBuffer(Line, strlen(Line));

	Offset = Sections[1].GetTranslation();
	sprintf(Line, "1 16 %f %f %f 1 0 0 0 1 0 0 0 1 4255.dat\n", Offset[0], Offset[1], Offset[2]);
	File.WriteBuffer(Line, strlen(Line));

	float Distance = Sections[0].GetTranslation().y - Sections[1].GetTranslation().y;
	float Scale = (Distance - 66.0f) / 44.0f;
	const char* SpringPart;

	if (!qstricmp(mPieceInfo->mFileName, "73129.dat"))
		SpringPart = "70038";
	else if (!qstricmp(mPieceInfo->mFileName, "41838.dat"))
		SpringPart = "41837";
	else if (!qstricmp(mPieceInfo->mFileName, "76138.dat"))
		SpringPart = "71953";
	else if (!qstricmp(mPieceInfo->mFileName, "76537.dat"))
		SpringPart = "22977";
	else
		return;

	Offset = Sections[0].GetTranslation();
	sprintf(Line, "1 494 %f %f %f 1 0 0 0 %f 0 0 0 1 %s.dat\n", Offset[0], Offset[1] - 10 - 44.0f * Scale, Offset[2], Scale, SpringPart);
	File.WriteBuffer(Line, strlen(Line));
}

void lcSynthInfo::AddActuatorParts(lcMemFile& File, lcArray<lcMatrix44>& Sections) const
{
	char Line[256];
	lcVector3 Offset;

	Offset = Sections[0].GetTranslation();
	sprintf(Line, "1 25 %f %f %f 0 1 0 -1 0 0 0 0 1 47157.dat\n", Offset[0], Offset[1], Offset[2]);
	File.WriteBuffer(Line, strlen(Line));
	sprintf(Line, "1 16 %f %f %f 1 0 0 0 1 0 0 0 1 62271c01.dat\n", Offset[0], Offset[1], Offset[2]);
	File.WriteBuffer(Line, strlen(Line));

	Offset = Sections[1].GetTranslation();
	sprintf(Line, "1 72 %f %f %f 1 0 0 0 1 0 0 0 1 62274c01.dat\n", Offset[0], Offset[1], Offset[2]);
	File.WriteBuffer(Line, strlen(Line));
}

lcMesh* lcSynthInfo::CreateMesh(const lcArray<lcPieceControlPoint>& ControlPoints) const
{
	lcArray<lcMatrix44> Sections;

	if (mCurve)
		CalculateCurveSections(ControlPoints, Sections, nullptr);
	else
		CalculateLineSections(ControlPoints, Sections, nullptr);

	lcLibraryMeshData MeshData;
	lcMemFile File; // todo: rewrite this to pass the parts directly

	switch (mType)
	{
	case lcSynthType::HOSE_FLEXIBLE:
		AddHoseFlexibleParts(File, Sections);
		break;

	case lcSynthType::FLEX_SYSTEM_HOSE:
		AddFlexHoseParts(File, MeshData, Sections);
		break;

	case lcSynthType::RIBBED_HOSE:
		AddRibbedHoseParts(File, Sections);
		break;

	case lcSynthType::FLEXIBLE_AXLE:
		AddFlexibleAxleParts(File, MeshData, Sections);
		break;

	case lcSynthType::STRING_BRAIDED:
		AddStringBraidedParts(File, MeshData, Sections);
		break;

	case lcSynthType::SHOCK_ABSORBER:
		AddShockAbsorberParts(File, Sections);
		break;

	case lcSynthType::ACTUATOR:
		AddActuatorParts(File, Sections);
		break;
	}

	File.WriteU8(0);

	lcArray<lcLibraryTextureMap> TextureStack;
	File.Seek(0, SEEK_SET);

	lcMeshLoader MeshLoader(MeshData, false, nullptr, false);
	if (MeshLoader.LoadMesh(File, LC_MESHDATA_SHARED))
		return MeshData.CreateMesh();

	return nullptr;
}

int lcSynthInfo::InsertControlPoint(lcArray<lcPieceControlPoint>& ControlPoints, const lcVector3& Start, const lcVector3& End) const
{
	lcArray<lcMatrix44> Sections;

	int BestSegment = -1;
	float BestTime;
	float BestDistance = FLT_MAX;
	lcVector3 BestPosition;

	CalculateCurveSections(ControlPoints, Sections,
		[&](const lcVector3& CurvePoint, int SegmentIndex, float t)
		{
			float Distance = lcRayPointDistance(CurvePoint, Start, End);
			if (Distance < BestDistance)
			{
				BestSegment = SegmentIndex;
				BestTime = t;
				BestDistance = Distance;
				BestPosition = lcVector3LDrawToLeoCAD(CurvePoint);
			}
		}
	);

	if (BestSegment != -1)
	{
		lcPieceControlPoint ControlPoint = ControlPoints[BestSegment];
		ControlPoint.Transform.SetTranslation(BestPosition);

		if (BestSegment != ControlPoints.GetSize() - 1)
		{
			lcPieceControlPoint NextControlPoint = ControlPoints[BestSegment + 1];
			ControlPoint.Scale = ControlPoint.Scale * (1.0f - BestTime) + NextControlPoint.Scale * BestTime;
		}

		ControlPoints.InsertAt(BestSegment + 1, ControlPoint);
	}

	return BestSegment + 1;
}
