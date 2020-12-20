#pragma once
#include "IW5CheatSP.h"


union DvarValue {
	bool enabled;
	int integer;
	unsigned int unsignedInt;
	float value;
	float vector[4];
	const char *string;
	char color[4];
};


struct dvar_t {
	const char *name;
	unsigned short flags;
	char type;
	bool modified;
	DvarValue current;
	DvarValue latched;
	DvarValue reset;
	char domain[8];
	dvar_t *hashNext;
};

struct LerpEntityStateTurret {
	float gunAngles[3];
	int lastBarrelRotChangeTime;
	unsigned __int16 lastBarrelRotChangeRate;
	unsigned __int16 lastHeatChangeLevel;
	int lastHeatChangeTime;
	bool isBarrelRotating;
	bool isOverheat;
	bool isHeatingUp;
	bool isOnCompass;
};
struct LerpEntityStateLoopFx {
	float cullDist;
	int period;
};
struct LerpEntityStateActor {
	char species;
	char stepMove;
	int lookAtEntityNum;
	int hitLocation;
	float impactVector[3];
	char headIcon;
	char headIconTeam;
};
struct LerpEntityStatePrimaryLight {
	char colorAndExp[4];
	float intensity;
	float radius;
	float cosHalfFovOuter;
	float cosHalfFovInner;
};
struct LerpEntityStatePlayer {
	int movementDir;
};
struct LerpEntityStateVehicle {
	unsigned int indices;
	unsigned int flags;
	float bodyPitch;
	float bodyRoll;
	float steerYaw;
	float gunPitch;
	float gunYaw;
};
struct LerpEntityStateMissile {
	int launchTime;
	int flightMode;
};
struct LerpEntityStateSoundBlend {
	float lerp;
	float volumeScale;
};
struct LerpEntityStateBulletTracer {
	float end[3];
};
struct LerpEntityStateBulletHit {
	float start[3];
};
struct LerpEntityStateEarthquake {
	float scale;
	float radius;
	int duration;
};
struct LerpEntityStateCustomExplode {
	int startTime;
};
struct LerpEntityStateExplosion {
	float innerRadius;
	float outerRadius;
	float magnitude;
};
struct LerpEntityStateExplosionJolt {
	float innerRadius;
	float outerRadius;
	float impulse[3];
};
struct LerpEntityStatePhysicsJitter {
	float innerRadius;
	float outerRadius;
	float minDisplacement;
	float maxDisplacement;
};
struct LerpEntityStateRadiusDamage {
	float range;
	int damageMin;
	int damageMax;
};
struct LerpEntityStateScriptMover {
	int entToTakeMarksFrom;
	int xModelIndex;
};


union LerpEntityStateTypeUnion {
	LerpEntityStateTurret turret;
	LerpEntityStateLoopFx loopFx;
	LerpEntityStateActor actor;
	LerpEntityStatePrimaryLight primaryLight;
	LerpEntityStatePlayer player;
	LerpEntityStateVehicle vehicle;
	LerpEntityStateMissile missile;
	LerpEntityStateSoundBlend soundBlend;
	LerpEntityStateBulletTracer bulletTracer;
	LerpEntityStateBulletHit bulletHit;
	LerpEntityStateEarthquake earthquake;
	LerpEntityStateCustomExplode customExplode;
	LerpEntityStateExplosion explosion;
	LerpEntityStateExplosionJolt explosionJolt;
	LerpEntityStatePhysicsJitter physicsJitter;
	LerpEntityStateRadiusDamage radiusDamage;
	LerpEntityStateScriptMover scriptMover;
};
struct trajectory_t {
	int trType;
	int trTime;
	int trDuration;
	float trBase[3];
	float trDelta[3];
};
struct LerpEntityState {
	int eFlags;
	trajectory_t pos;
	trajectory_t apos;
	LerpEntityStateTypeUnion u;
	int useCount;
};
struct StaticEntityStateVehicle {
	int team;
};
struct StaticEntityStateTurret {
	unsigned __int16 carrierEntNum;
};
union StaticEntityStateTypeUnion {
	StaticEntityStateVehicle vehicle;
	StaticEntityStateTurret turret;
};


struct entityState_s {
	char eType;
	char surfType;
	char __padding000[2];
	unsigned __int16 loopSound;
	char __padding001[2];
	unsigned int eventParm;
	LerpEntityState lerp;
	StaticEntityStateTypeUnion staticState;
	int weapon;
	int inAltWeaponMode;
	unsigned __int16 number;
	unsigned __int16 otherEntityNum;
	unsigned __int16 groundEntityNum;
	unsigned __int16 index;
	int time2;
	int solid;
	int eventSequence;
	char events[4];
	unsigned int eventParms[4];
	char __padding002[4];
};

struct Bounds {
	float midPoint[3];
	float halfSize[3];
};

struct EntHandle {
	unsigned __int16 number;
	unsigned __int16 infoIndex;
};

struct entityShared_t {
	char isLinked;
	char modelType;
	char svFlags;
	char eventType;
	char isInUse;
	Bounds box;
	int contents;
	Bounds absBox;
	float currentOrigin[3];
	float currentAngles[3];
	EntHandle ownerNum;
	int eventTime;
};


struct gentity_s
{
	entityState_s s;
	entityShared_t r;
	void *client;
	void *actor;
	void *sentient;
	void *vehicle;
	void *turret;
	int physObjId;
	char physicsObject;
	char takedamage;
	char active;
	char handler;
	unsigned __int16 classname;
	unsigned __int16 script_classname;
	unsigned __int16 script_linkName;
	unsigned __int16 script_noteworthy;
	unsigned __int16 target;
	unsigned __int16 targetname;
	unsigned int attachIgnoreCollision;
	int spawnflags;
	int flags;
	int clipmask;
	int processedFrame;
	EntHandle parent;
	int nextthink;
	int health;
	int maxHealth;
	int damage;
	EntHandle grenadeActivator;
	char __padding000[0x0060];
	EntHandle missileTargetEnt;
	EntHandle remoteControlledOwner;
	unsigned __int16 lookAtText0;
	unsigned __int16 lookAtText1;
	unsigned __int64 snd_wait;
	void *tagInfo;
	gentity_s *tagChildren;
	void *scripted;
	unsigned __int16 attachModelNames[31];
	unsigned __int16 attachTagNames[31];
	unsigned __int16 model;
	unsigned __int16 disconnectedLinks;
	int iDisconnectTime;
	float angleLerpRate;
	void *pAnimTree;
	gentity_s *nextFree;
};



struct level_locals_t {
	void *clients;
	void *gentities;
	int num_entities;
	void *firstFreeEnt;
	void *lastFreeEnt;
	void *sentients;
	void *actors;
	void *vehicles;
	void *turrets;
	int initializing;
	int clientIsSpawning;
	int maxclients;
	int framenum;
	int time;
	int previousTime;
	int timeAtLastPause;
	int respawnTime;
	int newSession;
	int actorCorpseCount;
	int actorCount;
};
struct scrVarPub_t {
	const char *fieldBuffer;
	bool evaluate;
	unsigned int time;
	unsigned int timeArrayId;
	unsigned int pauseArrayId;
	unsigned int notifyArrayId;
	unsigned int objectStackId;
	unsigned int levelId;
	unsigned int gameId;
	unsigned int animId;
	unsigned int freeEntList;
	unsigned int tempVariable;
	unsigned int numScriptValues[2];
	bool bInited;
	bool abort;
	unsigned short savecount;
	unsigned short savecountMark;
	unsigned int entId;
	unsigned int entFieldName;
	unsigned int checksum;
	void *programHunkUser;
	void *canonicalStringHunkUser;
	const char *programBuffer;
	unsigned short saveIdMap[36864];
	unsigned short saveIdMapRev[36864];
};


enum weapInventoryType_t {
	WEAPINVENTORY_PRIMARY = 0x0,
	WEAPINVENTORY_OFFHAND = 0x1,
	WEAPINVENTORY_ITEM = 0x2,
	WEAPINVENTORY_ALTMODE = 0x3,
	WEAPINVENTORY_EXCLUSIVE = 0x4,
	WEAPINVENTORY_SCAVENGER = 0x5,
	WEAPINVENTORYCOUNT = 0x6,
};


struct StateTimers {
	int iFireDelay;
	int iMeleeDelay;
	int meleeChargeDelay;
	int iDetonateDelay;
	int iRechamberTime;
	int rechamberTimeOneHanded;
	int iRechamberBoltTime;
	int iHoldFireTime;
	int iDetonateTime;
	int iMeleeTime;
	int meleeChargeTime;
	int iReloadTime;
	int reloadShowRocketTime;
	int iReloadEmptyTime;
	int iReloadAddTime;
	int iReloadStartTime;
	int iReloadStartAddTime;
	int iReloadEndTime;
	int iDropTime;
	int iRaiseTime;
	int iAltDropTime;
	int quickDropTime;
	int quickRaiseTime;
	int iBreachRaiseTime;
	int iEmptyRaiseTime;
	int iEmptyDropTime;
	int sprintInTime;
	int sprintLoopTime;
	int sprintOutTime;
	int stunnedTimeBegin;
	int stunnedTimeLoop;
	int stunnedTimeEnd;
	int nightVisionWearTime;
	int nightVisionWearTimeFadeOutEnd;
	int nightVisionWearTimePowerUp;
	int nightVisionRemoveTime;
	int nightVisionRemoveTimePowerDown;
	int nightVisionRemoveTimeFadeInStart;
	int fuseTime;
	int aiFuseTime;
	int blastFrontTime;
	int blastRightTime;
	int blastBackTime;
	int blastLeftTime;
	int raiseInterruptableTime;
	int firstRaiseInterruptableTime;
	int reloadInterruptableTime;
	int reloadEmptyInterruptableTime;
	int fireInterruptableTime;
};


struct ADSOverlay {
	void *shader;
	void *shaderLowRes;
	void *shaderEMP;
	void *shaderEMPLowRes;
	int reticle;
	float width;
	float height;
	float widthSplitscreen;
	float heightSplitscreen;
};


struct WeaponDef {
	const char *szOverlayName;
	void **gunXModel;
	void *handXModel;
	const char **szXAnimsRightHanded;
	const char **szXAnimsLeftHanded;
	const char *szModeName;
	unsigned __int16 *notetrackSoundMapKeys;
	unsigned __int16 *notetrackSoundMapValues;
	unsigned __int16 *notetrackRumbleMapKeys;
	unsigned __int16 *notetrackRumbleMapValues;
	int playerAnimType;
	int weapType;
	int weapClass;
	int penetrateType;
	weapInventoryType_t inventoryType;
	int fireType;
	int offhandClass;
	int stance;
	void *viewFlashEffect;
	void *worldFlashEffect;
	void *pickupSound;
	void *pickupSoundPlayer;
	void *ammoPickupSound;
	void *ammoPickupSoundPlayer;
	void *projectileSound;
	void *pullbackSound;
	void *pullbackSoundPlayer;
	void *fireSound;
	void *fireSoundPlayer;
	void *fireSoundPlayerAkimbo;
	void *fireLoopSound;
	void *fireLoopSoundPlayer;
	void *fireStopSound;
	void *fireStopSoundPlayer;
	void *fireLastSound;
	void *fireLastSoundPlayer;
	void *emptyFireSound;
	void *emptyFireSoundPlayer;
	void *meleeSwipeSound;
	void *meleeSwipeSoundPlayer;
	void *meleeHitSound;
	void *meleeMissSound;
	void *rechamberSound;
	void *rechamberSoundPlayer;
	void *reloadSound;
	void *reloadSoundPlayer;
	void *reloadEmptySound;
	void *reloadEmptySoundPlayer;
	void *reloadStartSound;
	void *reloadStartSoundPlayer;
	void *reloadEndSound;
	void *reloadEndSoundPlayer;
	void *detonateSound;
	void *detonateSoundPlayer;
	void *nightVisionWearSound;
	void *nightVisionWearSoundPlayer;
	void *nightVisionRemoveSound;
	void *nightVisionRemoveSoundPlayer;
	void *altSwitchSound;
	void *altSwitchSoundPlayer;
	void *raiseSound;
	void *raiseSoundPlayer;
	void *firstRaiseSound;
	void *firstRaiseSoundPlayer;
	void *putawaySound;
	void *putawaySoundPlayer;
	void *scanSound;
	void *changeVariableZoomSound;
	void **bounceSound;
	void **rollingSound;
	void *viewShellEjectEffect;
	void *worldShellEjectEffect;
	void *viewLastShotEjectEffect;
	void *worldLastShotEjectEffect;
	void *reticleCenter;
	void *reticleSide;
	int iReticleCenterSize;
	int iReticleSideSize;
	int iReticleMinOfs;
	int activeReticleType;
	float vStandMove[3];
	float vStandRot[3];
	float strafeMove[3];
	float strafeRot[3];
	float vDuckedOfs[3];
	float vDuckedMove[3];
	float vDuckedRot[3];
	float vProneOfs[3];
	float vProneMove[3];
	float vProneRot[3];
	float fPosMoveRate;
	float fPosProneMoveRate;
	float fStandMoveMinSpeed;
	float fDuckedMoveMinSpeed;
	float fProneMoveMinSpeed;
	float fPosRotRate;
	float fPosProneRotRate;
	float fStandRotMinSpeed;
	float fDuckedRotMinSpeed;
	float fProneRotMinSpeed;
	void **worldModel;
	void *worldClipModel;
	void *rocketModel;
	void *knifeModel;
	void *worldKnifeModel;
	void *hudIcon;
	int hudIconRatio;
	void *pickupIcon;
	int pickupIconRatio;
	void *ammoCounterIcon;
	int ammoCounterIconRatio;
	int ammoCounterClip;
	int iStartAmmo;
	const char *szAmmoName;
	int iAmmoIndex;
	const char *szClipName;
	int iClipIndex;
	int iMaxAmmo;
	int shotCount;
	const char *szSharedAmmoCapName;
	int iSharedAmmoCapIndex;
	int iSharedAmmoCap;
	int damage;
	int playerDamage;
	int iMeleeDamage;
	int iDamageType;
	StateTimers stateTimers;
	StateTimers akimboStateTimers;
	float autoAimRange;
	float aimAssistRange;
	float aimAssistRangeAds;
	float aimPadding;
	float enemyCrosshairRange;
	float moveSpeedScale;
	float adsMoveSpeedScale;
	float sprintDurationScale;
	float fAdsZoomInFrac;
	float fAdsZoomOutFrac;
	ADSOverlay overlay;
	int overlayInterface;
	float fAdsBobFactor;
	float fAdsViewBobMult;
	float fHipSpreadStandMin;
	float fHipSpreadDuckedMin;
	float fHipSpreadProneMin;
	float hipSpreadStandMax;
	float hipSpreadDuckedMax;
	float hipSpreadProneMax;
	float fHipSpreadDecayRate;
	float fHipSpreadFireAdd;
	float fHipSpreadTurnAdd;
	float fHipSpreadMoveAdd;
	float fHipSpreadDuckedDecay;
	float fHipSpreadProneDecay;
	float fHipReticleSidePos;
	float fAdsIdleAmount;
	float fHipIdleAmount;
	float adsIdleSpeed;
	float hipIdleSpeed;
	float fIdleCrouchFactor;
	float fIdleProneFactor;
	float fGunMaxPitch;
	float fGunMaxYaw;
	float adsIdleLerpStartTime;
	float adsIdleLerpTime;
	float swayMaxAngle;
	float swayLerpSpeed;
	float swayPitchScale;
	float swayYawScale;
	float swayHorizScale;
	float swayVertScale;
	float swayShellShockScale;
	float adsSwayMaxAngle;
	float adsSwayLerpSpeed;
	float adsSwayPitchScale;
	float adsSwayYawScale;
	float adsSwayHorizScale;
	float adsSwayVertScale;
	float adsViewErrorMin;
	float adsViewErrorMax;
	void *physCollmap;
	float dualWieldViewModelOffset;
	int killIconRatio;
	int iReloadAmmoAdd;
	int iReloadStartAdd;
	int ammoDropStockMin;
	int ammoDropClipPercentMin;
	int ammoDropClipPercentMax;
	int iExplosionRadius;
	int iExplosionRadiusMin;
	int iExplosionInnerDamage;
	int iExplosionOuterDamage;
	float damageConeAngle;
	float bulletExplDmgMult;
	float bulletExplRadiusMult;
	int iProjectileSpeed;
	int iProjectileSpeedUp;
	int iProjectileSpeedForward;
	int iProjectileActivateDist;
	float projLifetime;
	float timeToAccelerate;
	float projectileCurvature;
	void *projectileModel;
	int projExplosion;
	void *projExplosionEffect;
	void *projDudEffect;
	void *projExplosionSound;
	void *projDudSound;
	int stickiness;
	float lowAmmoWarningThreshold;
	float ricochetChance;
	bool riotShieldEnableDamage;
	int riotShieldHealth;
	float riotShieldDamageMult;
	float *parallelBounce;
	float *perpendicularBounce;
	void *projTrailEffect;
	void *projBeaconEffect;
	float vProjectileColor[3];
	int guidedMissileType;
	float maxSteeringAccel;
	int projIgnitionDelay;
	void *projIgnitionEffect;
	void *projIgnitionSound;
	float fAdsAimPitch;
	float fAdsCrosshairInFrac;
	float fAdsCrosshairOutFrac;
	int adsGunKickReducedKickBullets;
	float adsGunKickReducedKickPercent;
	float fAdsGunKickPitchMin;
	float fAdsGunKickPitchMax;
	float fAdsGunKickYawMin;
	float fAdsGunKickYawMax;
	float fAdsGunKickAccel;
	float fAdsGunKickSpeedMax;
	float fAdsGunKickSpeedDecay;
	float fAdsGunKickStaticDecay;
	float fAdsViewKickPitchMin;
	float fAdsViewKickPitchMax;
	float fAdsViewKickYawMin;
	float fAdsViewKickYawMax;
	float fAdsViewScatterMin;
	float fAdsViewScatterMax;
	float fAdsSpread;
	int hipGunKickReducedKickBullets;
	float hipGunKickReducedKickPercent;
	float fHipGunKickPitchMin;
	float fHipGunKickPitchMax;
	float fHipGunKickYawMin;
	float fHipGunKickYawMax;
	float fHipGunKickAccel;
	float fHipGunKickSpeedMax;
	float fHipGunKickSpeedDecay;
	float fHipGunKickStaticDecay;
	float fHipViewKickPitchMin;
	float fHipViewKickPitchMax;
	float fHipViewKickYawMin;
	float fHipViewKickYawMax;
	float fHipViewScatterMin;
	float fHipViewScatterMax;
	float fightDist;
	float maxDist;
	const char *accuracyGraphName[2];
	float(*originalAccuracyGraphKnots[2])[2];
	unsigned __int16 originalAccuracyGraphKnotCount[2];
	int iPositionReloadTransTime;
	float leftArc;
	float rightArc;
	float topArc;
	float bottomArc;
	float accuracy;
	float aiSpread;
	float playerSpread;
	float minTurnSpeed[2];
	float maxTurnSpeed[2];
	float pitchConvergenceTime;
	float yawConvergenceTime;
	float suppressTime;
	float maxRange;
	float fAnimHorRotateInc;
	float fPlayerPositionDist;
	const char *szUseHintString;
	const char *dropHintString;
	int iUseHintStringIndex;
	int dropHintStringIndex;
	float horizViewJitter;
	float vertViewJitter;
	float scanSpeed;
	float scanAccel;
	int scanPauseTime;
	const char *szScript;
	float fOOPosAnimLength[2];
	int minDamage;
	int minPlayerDamage;
	float fMaxDamageRange;
	float fMinDamageRange;
	float destabilizationRateTime;
	float destabilizationCurvatureMax;
	int destabilizeDistance;
	float *locationDamageMultipliers;
	const char *fireRumble;
	const char *meleeImpactRumble;
	void *tracerType;
	bool turretADSEnabled;
	float turretADSTime;
	float turretFov;
	float turretFovADS;
	float turretScopeZoomRate;
	float turretScopeZoomMin;
	float turretScopeZoomMax;
	float turretOverheatUpRate;
	float turretOverheatDownRate;
	float turretOverheatPenalty;
	void *turretOverheatSound;
	void *turretOverheatEffect;
	const char *turretBarrelSpinRumble;
	float turretBarrelSpinSpeed;
	float turretBarrelSpinUpTime;
	float turretBarrelSpinDownTime;
	void *turretBarrelSpinMaxSnd;
	void *turretBarrelSpinUpSnd[4];
	void *turretBarrelSpinDownSnd[4];
	void *missileConeSoundAlias;
	void *missileConeSoundAliasAtBase;
	float missileConeSoundRadiusAtTop;
	float missileConeSoundRadiusAtBase;
	float missileConeSoundHeight;
	float missileConeSoundOriginOffset;
	float missileConeSoundVolumescaleAtCore;
	float missileConeSoundVolumescaleAtEdge;
	float missileConeSoundVolumescaleCoreSize;
	float missileConeSoundPitchAtTop;
	float missileConeSoundPitchAtBottom;
	float missileConeSoundPitchTopSize;
	float missileConeSoundPitchBottomSize;
	float missileConeSoundCrossfadeTopSize;
	float missileConeSoundCrossfadeBottomSize;
	bool sharedAmmo;
	bool lockonSupported;
	bool requireLockonToFire;
	bool isAirburstWeapon;
	bool bigExplosion;
	bool noAdsWhenMagEmpty;
	bool avoidDropCleanup;
	bool inheritsPerks;
	bool crosshairColorChange;
	bool bRifleBullet;
	bool armorPiercing;
	bool bBoltAction;
	bool aimDownSight;
	bool canHoldBreath;
	bool canVariableZoom;
	bool bRechamberWhileAds;
	bool bBulletExplosiveDamage;
	bool bCookOffHold;
	bool bClipOnly;
	bool noAmmoPickup;
	bool adsFireOnly;
	bool cancelAutoHolsterWhenEmpty;
	bool disableSwitchToWhenEmpty;
	bool suppressAmmoReserveDisplay;
	bool laserSightDuringNightvision;
	bool markableViewmodel;
	bool noDualWield;
	bool flipKillIcon;
	bool bNoPartialReload;
	bool bSegmentedReload;
	bool blocksProne;
	bool silenced;
	bool isRollingGrenade;
	bool projExplosionEffectForceNormalUp;
	bool bProjImpactExplode;
	bool stickToPlayers;
	bool stickToVehicles;
	bool stickToTurrets;
	bool hasDetonator;
	bool disableFiring;
	bool timedDetonation;
	bool rotate;
	bool holdButtonToThrow;
	bool freezeMovementWhenFiring;
	bool thermalScope;
	bool altModeSameWeapon;
	bool turretBarrelSpinEnabled;
	bool missileConeSoundEnabled;
	bool missileConeSoundPitchshiftEnabled;
	bool missileConeSoundCrossfadeEnabled;
	bool offhandHoldIsCancelable;
	bool doNotAllowAttachmentsToOverrideSpread;
	unsigned __int16 stowTag;
	void *stowOffsetModel;
};


struct color_s {
	char R, G, B, A;
	color_s(int r, int g, int b, int a);
};

struct hudelem_s {
	int type;
	float x;
	float y;
	float z;
	int targetEntNum;
	float fontScale;
	float fromFontScale;
	int fontScaleStartTime;
	int fontScaleTime;
	int font;
	int alignOrg;
	int alignScreen;
	color_s color;
	color_s fromColor;
	int fadeStartTime;
	int fadeTime;
	int label;
	int width;
	int height;
	int materialIndex;
	int fromWidth;
	int fromHeight;
	int scaleStartTime;
	int scaleTime;
	float fromX;
	float fromY;
	int fromAlignOrg;
	int fromAlignScreen;
	int moveStartTime;
	int moveTime;
	int time;
	int duration;
	float value;
	int text;
	float sort;
	color_s glowColor;
	int fxBirthTime;
	int fxLetterTime;
	int fxDecayStartTime;
	int fxDecayDuration;
	int soundID;
	int flags;
};


struct game_hudelem_s {
	hudelem_s elem;
	int clientNum;
};



union VariableUnion {
	int intValue;
	unsigned int uintValue;
	float floatValue;
	unsigned int stringValue;
	const float *vectorValue;
	const char *codePosValue;
	unsigned int pointerValue;
	unsigned int entityOffset;
};


struct VariableValue {
	VariableUnion u;
	int type;
};

struct DBFile {
private:
	char __padding000[0x0004];
public:

	char name[64];

private:
	char __padding001[0x0020];
public:
	char *memoryBuffer;
	unsigned int memoryBufferSize;

};
