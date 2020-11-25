#include "BoHUDComponent.h"

char16_t gaaMultiplierStrings[4];

class CBoHUDBoostBar : CBoHUDComponent {
	enum EMessageType {
		eMessageOncoming = 0,
		eMessageDrift = 1,
		eMessageNearMiss = 2,
		eMessageAir = 3,
		eMessageTailgate = 4,
		eMessageGrinding = 5,
		eMessageRubbing = 6,
		eMessageCheckedTraffic = 7,
		eMessageNum = 8
	};

	class CBoostMessage {
	public:
		bool Prepare(EMessageType, unsigned const short*);
	};

	class CBoostBarObjectData {
		class CParticle {
			void Init();
		};

	public:
		bool Prepare();
	};

	class C2dObjectBoostBar {
	public:
		void Prepare(
			const GtMathPs2::CGtV2d&, 
			const GtMathPs2::CGtV2d&, 
			GtMathPs2::CGtV4d, 
			CBoHUDBoostBar::CBoostBarObjectData*
		);
		void _Render(const CGt2dObject::CGt2dObjectSpace&, const void*);
		void _RenderBackground(
			const CGt2dObject::CGt2dObjectSpace&, 
			float, 
			int, 
			float, 
			float, 
			bool, 
			const C2dObjectBoostBar::C2dObjectBoostBarData*
		);
		void _RenderParticles(
			const BoHUDParticleParamsTag*, 
			const CGt2dObject::CGt2dObjectSpace&, 
			const CBoHUDBoostBar::CBoostBarObjectData::CParticle*, 
			int, 
			float, 
			bool
		);
	};

	class C2dObjectBoostBarMessage {
	public:
		void Prepare(
			const GtMathPs2::CGtV2d&, 
			const GtMathPs2::CGtV2d&, 
			CBoHUDBoostBar::CBoostMessage*
		);
		void _Render(const CGt2dObject::CGt2dObjectSpace&, const void*);
		RwInt32 _BuildBatchData(
			const CGt2dObject::CGt2dObjectSpace& lObjectSpace,
			const GtMathPs2::CGtV2d&, 
			const C2dObjectBoostBarMessage::C2dObjectBoostBarMessageData* lpBoostBarMessageData
		);
	};
public:
	void StaticConstruct();
	bool Prepare(EPlayerCarIndex, EHUDAlign, int, bool, bool);
	void PrepareBoostBarPercentageObject();
	void PrepareTapForCrashbreakerObject(float);
	void BarUpdate(float);
	void UpdateTakedownAnimation(float);
	bool UpdateBoostMessage(CBoHUDBoostBar::EMessageType, const CBoScoreCategory*, float, float);
	void MessagesUpdate(float);
	void Update(float);
	void UpdateTransition(float, bool, EHUDMode, EHUDMode);
	void StartTakedownAnimation();
	void StopTakedownAnimation();

private:

};