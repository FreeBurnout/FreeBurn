#include "BoHUDComponent.h"
#include "../World/Common/BoOffensiveDrivingManager.h"
#include "../../Shared/Numeric/Math/PC/GtMathPC.h"
#include "../../Shared/Graphical/Common/2D/Gt2dObject.h"

char16_t gaaMultiplierStrings[4];

using namespace GtMathPC;

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
	public:
		class CParticle {
			void Init();
		};

		bool Prepare();
	};

	class C2dObjectBoostBar {
	public:
		struct C2dObjectBoostBarData {
			CBoostBarObjectData* mpObjectData;
			int maPad[5];
		};

		void Prepare(
			const CGtV2d&, 
			const CGtV2d&, 
			CGtV4d, 
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
			const C2dObjectBoostBarData*
		);
		void _RenderParticles(
			const BoHUDParticleParamsTag*, 
			const CGt2dObject::CGt2dObjectSpace&, 
			const CBoostBarObjectData::CParticle*, 
			int, 
			float, 
			bool
		);
	};

	class C2dObjectBoostBarMessage {
	public:
		struct C2dObjectBoostBarMessageData {
			CBoostMessage* mpBoostMessage;
		};

		void Prepare(const CGtV2d&, const CGtV2d&, CBoHUDBoostBar::CBoostMessage*);
		void _Render(const CGt2dObject::CGt2dObjectSpace&, const void*);
		RwInt32 _BuildBatchData(
			const CGt2dObject::CGt2dObjectSpace& lObjectSpace,
			const CGtV2d&, 
			const C2dObjectBoostBarMessageData* lpBoostBarMessageData
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