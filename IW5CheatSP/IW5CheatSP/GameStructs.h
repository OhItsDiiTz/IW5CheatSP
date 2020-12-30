#pragma once
#include "IW5CheatSP.h"


struct gentity_s;
struct VariableValue;
struct hudelem_s;

struct UiContext {

};

struct menuDef_t {

};

enum ButtonBits {
	BUTTON_FIRE = 0x01,
	BUTTON_AIM = 0x80800,
	BUTTON_MELEE = 0x4,
	BUTTON_TACTICAL = 0x8000,
	BUTTON_LETHAL = 0x4000,
	BUTTON_RELOAD = 0x10,
	BUTTON_JUMP = 0x400,
	BUTTON_SPRINT = 0x2002,
};

struct usercmd_s {
	int serverTime;
	int buttons;
	int angles[3];
	int weapon;
	int offHand;
	char forwardmove;
	char rightmove;
	char upmove;
	char downmove;
	char pitchmove;
	char yawmove;
	float gunPitch;
	float gunYaw;
	float gunXOfs;
	float gunYOfs;
	float gunZOfs;
	__int16 meleeChargeYaw;
	char meleeChargeDist;
	char selectedLoc[2];
	char selectedLocAngle;
	char remoteControlAngles[2];
};


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

struct item_ent_t {
	int ammoCount;
	int clipAmmoCount[2];
	int weapon;
	bool dualWieldItem;
	int shieldHealth;
};

struct spawner_ent_t {
	int team;
	int timestamp;
	int index;
	int count;
};

struct trigger_ent_t {
	int threshold;
	int accumulate;
	int timestamp;
	bool requireLookAt;
};

struct mover_positions_t {
	float decelTime;
	float speed;
	float midTime;
	float pos1[3];
	float pos2[3];
	float pos3[3];
};

struct mover_slidedata_t {
	Bounds bounds;
	float velocity[3];
};

union another_union {
	mover_positions_t pos;
	mover_slidedata_t slide;
};

struct mover_ent_t {
	another_union ___u0;
	mover_positions_t angle;
};

struct corpse_ent_t {
	int removeTime;
};

struct actor_ent_t {
	int spawnTime;
};

struct missile_fields_grenade {
	float predictLandPos[3];
	int predictLandTime;
	float wobbleCycle;
	float curve;
};

struct missile_fields_nonGrenade {
	float curvature[3];
	float targetEntOffset[3];
	float targetPos[3];
	float launchOrigin[3];
	int stage;
};


union another_union_1 {
	missile_fields_grenade grenade;
	missile_fields_nonGrenade nonGrenade;
};


struct missile_ent_t {
	int timestamp;
	float time;
	int timeOfBirth;
	float travelDist;
	float surfaceNormal[3];
	int team;
	int flags;
	another_union_1 ___u7;
};

struct blend_ent_t {
	float pos[3];
	float vel[3];
	float viewQuat[4];
	bool changed;
	float accelTime;
	float decelTime;
	float startTime;
	float totalTime;
};


union some_ent_union {
	item_ent_t item[2];
	spawner_ent_t spawner;
	trigger_ent_t trigger;
	mover_ent_t mover;
	corpse_ent_t corpse;
	actor_ent_t actorInfo;
	missile_ent_t missile;
	blend_ent_t blend;
};

struct playerEvents_t {
	int eventSequence;
	int events[4];
	unsigned int eventParms[4];
	int oldEventSequence;
	int timeADSCameUp;
};

struct SprintState {
	int sprintButtonUpRequired;
	int sprintDelay;
	int lastSprintStart;
	int lastSprintEnd;
	int sprintStartMaxLength;
};

struct MantleState {
	float yaw;
	int timer;
	int transIndex;
	int flags;
};

struct PlayerActiveWeaponState {
	int weapAnim;
	int weaponTime;
	int weaponDelay;
	int weaponRestrictKickTime;
	int weaponState;
	int weapHandFlags;
	unsigned int weaponShotCount;
};

struct PlayerEquippedWeaponState {
	bool usedBefore;
	bool dualWielding;
	bool inAltMode;
	bool needsRechamber[2];
	int zoomLevelIndex;
};

struct GlobalAmmo {
	int ammoType;
	int ammoCount;
};

struct ClipAmmo {
	int clipIndex;
	int ammoCount[2];
};


struct PlayerWeaponCommonState {
	int offHand;
	int offhandPrimary;
	int offhandSecondary;
	int weapon;
	int weapFlags;
	float fWeaponPosFrac;
	float aimSpreadScale;
	int adsDelayTime;
	int spreadOverride;
	int spreadOverrideState;
	float fAimSpreadMovementScale;
	int lastWeaponHand; //PlayerHandIndex
	GlobalAmmo ammoNotInClip[15];
	ClipAmmo ammoInClip[15];
	int weapLockFlags;
	int weapLockedEntnum;
	float weapLockedPos[3];
	int weaponIdleTime;
	int forcedViewAnimWeapon;
	int forcedViewAnimWeaponState;
	int forcedViewAnimOriginalWeapon;
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

struct playerState_s {
	int commandTime;
	int pm_type;
	int pm_time;
	int pm_flags;
	int otherFlags;
	int linkFlags;
	int bobCycle;
	float origin[3];
	float velocity[3];
	int grenadeTimeLeft;
	int throwbackGrenadeOwner;
	int throwbackGrenadeTimeLeft;
	int throwbackWeapon;
	int remoteEyesEnt;
	int remoteEyesTagname;
	int remoteControlEnt;
	int vehicleViewCalcEnt;
	int foliageSoundTime;
	int gravity;
	int speed;
	float delta_angles[3];
	int groundEntityNum;
	float vLadderVec[3];
	int jumpTime;
	float jumpOriginZ;
	int legsTimer;
	int legsAnim;
	int torsoTimer;
	int torsoAnim;
	int legsAnimDuration;
	int torsoAnimDuration;
	int damageTimer;
	int damageDuration;
	int flinchYawAnim;
	int movementDir;
	int eFlags;
	playerEvents_t pe;
	int unpredictableEventSequence;
	int unpredictableEventSequenceOld;
	int unpredictableEvents[4];
	unsigned int unpredictableEventParms[4];
	int clientNum;
	int viewmodelIndex;
	float viewangles[3];
	int viewHeightTarget;
	float viewHeightCurrent;
	int viewHeightLerpTime;
	int viewHeightLerpTarget;
	int viewHeightLerpDown;
	float viewAngleClampBase[2];
	float viewAngleClampRange[2];
	float viewAngleResistMax[2];
	float viewAngleResistMin[2];
	int damageEvent;
	int damageYaw;
	int damagePitch;
	int damageCount;
	int damageFlags;
	int stats[4];
	float proneDirection;
	float proneDirectionPitch;
	float proneTorsoPitch;
	int viewlocked; //ViewLockTypes
	int viewlocked_entNum;
	float linkAngles[3];
	float linkWeaponAngles[3];
	int linkWeaponEnt;
	int loopSound;
	int vehicleType;
	float groundTiltAngles[3];
	int cursorHint;
	int cursorHintString;
	int cursorHintEntIndex;
	int cursorHintDualWield;
	int motionTrackerEnabled;
	int locationSelectionInfo;
	SprintState sprintState;
	float holdBreathScale;
	int holdBreathTimer;
	float moveSpeedScaleMultiplier;
	MantleState mantleState;
	PlayerActiveWeaponState weapState[2];
	int weaponsEquipped[15];
	PlayerEquippedWeaponState weapEquippedData[15];
	PlayerWeaponCommonState weapCommon;
	int meleeChargeDist;
	int meleeChargeTime;
	float meleeChargeYaw;
	unsigned int perks[2];
	unsigned int perkSlots[9];
	int actionSlotType[4]; //ActionSlotType
	int actionSlotParam[4];
	int weaponHudIconOverrides[6];
	int animScriptedType;
	int shellshockIndex;
	int shellshockTime;
	int shellshockDuration;
	float viewKickScale;
	float dofNearStart;
	float dofNearEnd;
	float dofFarStart;
	float dofFarEnd;
	float dofNearBlur;
	float dofFarBlur;
	float dofViewmodelStart;
	float dofViewmodelEnd;
	hudelem_s elem[256];
	int recoilScale;
	int diveDirection;
	int stunTime;
};

struct clientPersistent_t {
	int connected; //clientConnected_t
	usercmd_s cmd;
	usercmd_s oldcmd;
	int maxHealth;
	float moveSpeedScaleMultiplier;
	int motionTrackerEnabled;
	char playerName[32];
};

struct viewClamp {
	float start[2];
	float current[2];
	float goal[2];
};


struct viewClampState {
	viewClamp min;
	viewClamp max;
	viewClamp resistMax;
	viewClamp resistMin;
	float accelTime;
	float decelTime;
	float totalTime;
	float startTime;
};


struct gclient_s {
	playerState_s ps;
	clientPersistent_t pers;
	int flags;
	int buttons;
	int oldbuttons;
	int latched_buttons;
	int buttonsSinceLastFrame;
	float fGunPitch;
	float fGunYaw;
	float fGunXOfs;
	float fGunYOfs;
	float fGunZOfs;
	int damage_blood;
	int damage_stun;
	float damage_from[3];
	int damage_fromWorld;
	float currentAimSpreadScale;
	gentity_s *pHitHitEnt;
	EntHandle pLookatEnt;
	float prevLinkedInvQuat[4];
	bool prevLinkAnglesSet;
	bool link_rotationMovesEyePos;
	bool link_doCollision;
	bool link_useTagAnglesForViewAngles;
	bool link_useBaseAnglesForViewClamp;
	float linkAnglesFrac;
	viewClampState link_viewClamp;
	int inControlTime;
	int lastTouchTime;
	EntHandle useHoldEntity;
	int useHoldTime;
	int useButtonDone;
	int bDisableAutoPickup;
	float criticalBulletDamageDist;
	int invulnerableDuration;
	int invulnerableExpireTime;
	bool invulnerableActivated;
	bool invulnerableEnabled;
	bool deathShieldEnabled;
	char attackerCount;
	float attackerAccuracyMultiplier;
	float accuracyDistMultiplier;
	float damageMultiplier;
	bool playerMoved;
	float playerLOSCheckPos[2];
	float playerLOSCheckDir[2];
	int playerLOSPosTime;
	int playerADSTargetTime;
	float futurePos[3];
	int futurePosUpdateTime;
	int lastWeapon;
	bool lastWeaponAltStatus;
	int lastStowedWeapon;
	bool previouslyFiring;
	bool previouslyFiringLeftHand;
	bool previouslyUsingNightVision;
	bool groundEntChanged;
	int groundTiltEntNum;
	int hudElemLastAssignedSoundID;
	int visionDuration[5];
	char visionName[5][64];
	void *weaponModel;
	void *knifeModel;
	int lastStand;
	unsigned __int16 attachShieldTagName;
	int shieldHealth;
	int hintForcedType;
	int hintForcedString;
};

struct gentity_s {
	entityState_s s;
	entityShared_t r;
	gclient_s *client;
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
	some_ent_union __us;
	EntHandle missileTargetEnt;
	EntHandle remoteControlledOwner;
	unsigned __int16 lookAtText0;
	unsigned __int16 lookAtText1;
	char snd_wait[6];
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

struct ai_transition_cmd_t {
	int eTransition;
	int eState;
};

struct ActorShoot {
	float accuracy;
	float playerSightAccuracy;
	unsigned int missCount;
	unsigned int hitCount;
	float debugLastAccuracy;
	int lastShotTime;
	bool lastCanShootEnemyResult;
	int lastCanShootEnemyTime;
};

struct ActorOrientation {
	float fDesiredBodyYaw;
	float fLookPitch;
	float fLookYaw;
	float maxFaceEnemyDistSq;
	char relativeDir;
	char prevRelativeDir;
	bool faceMotion;
	bool gunBlockedByWall;
	bool lockScriptOrient;
	float vLookForward[3];
	float vLookRight[3];
	float vLookUp[3];
};

struct ai_orient_t{
	int eMode;
	float fDesiredLookPitch;
	float fDesiredLookYaw;
	float fDesiredBodyYaw;
};

struct ActorPainDeath {
	int iPainTime;
	int minPainDamage;
	bool allowPain;
	bool allowDeath;
	bool delayedDeath;
	bool dieQuietly;
	bool forceRagdollImmediate;
	int iDamageTaken;
	int iDamageYaw;
	float damageDir[3];
	unsigned __int16 damageHitLoc;
	unsigned __int16 damageWeapon;
	int damageMOD;
};

struct ActorProne {
	unsigned __int16 animProneLow;
	unsigned __int16 animProneLevel;
	unsigned __int16 animProneHigh;
	bool bProneOK;
	char feetDirection;
	float fInvProneAnimLowPitch;
	float fInvProneAnimHighPitch;
	float fProneLastDiff;
};

struct actor_prone_info_s {
	bool bCorpseOrientation;
	bool orientPitch;
	bool prone;
	int iProneTime;
	int iProneTrans;
	float fBodyHeight;
	float fBodyPitch;
	float fWaistPitch;
};

struct ActorCachedInfo {
	int time;
	float pos[3];
	float dir[3];
};

struct ActorLookAtInfo {
	float vLookAtPos[3];
	float fLookAtTurnAngle;
	float fLookAtTurnSpeed;
	float fLookAtTurnAccel;
	float fLookAtAnimYawLimit;
	float fLookAtYawLimit;
	unsigned __int16 animLookAtStraight;
	unsigned __int16 animLookAtLeft;
	unsigned __int16 animLookAtRight;
	bool bDoLookAt;
	bool bLookAtSetup;
	int iLookAtBlendEndTime;
	float fLookAtAnimBlendRate;
	float fLookAtLimitBlendRate;
};

struct ActorDelayedWeaponDrop {
	float matrix[4][3];
	int time;
	unsigned __int16 tagName;
	int state; //DelayedWeapDropState
	int weapon;
};

struct ActorCoverArrivalInfo {
	int arrivalNotifyRequested;
	int animscriptOverrideRunTo;
	float animscriptOverrideRunToPos[3];
	float offsetIncrement[2];
	int offsetAdjustCount;
	float arrivalYaw;
	EntHandle scriptedArrivalEnt;
};

struct ActorNodeSelect {
	int numCoverNodesInGoal;
	int iPotentialCoverNodeCount;
	int iPotentialAmbushNodeCount;
	int nextFindBestCoverTime;
	bool requestDifferentCover;
	bool keepClaimedNode;
	bool keepClaimedNodeIfValid;
	bool keepNodeDuringScriptedAnim;
	bool doDangerReact;
	int dangerReactGoalTime;
	int dangerReactDuration;
	float engageMinDist;
	float engageMinFalloffDist;
	float engageMaxDist;
	float engageMaxFalloffDist;
};

struct ActorSight {
	float fovDot;
	float fovDotBusy;
	float fMaxSightDistSqrd;
	int latency;
	bool ignoreCloseFoliage;
	bool lastEnemySightPosValid;
	float lastEnemySightPos[3];
	float anglesToLikelyEnemyPath[3];
	int faceLikelyEnemyPathNeedCheckTime;
	int faceLikelyEnemyPathNeedRecalculateTime;
	void *faceLikelyEnemyPathNode;
	float upAimLimit;
	float downAimLimit;
	float rightAimLimit;
	float leftAimLimit;
};

struct vis_cache_t {
	bool bVisible;
	int iLastUpdateTime;
	int iLastVisTime;
};


struct sentient_info_t {
	vis_cache_t VisCache;
	int iLastAttackMeTime;
	int lastKnownPosTime;
	int attackTime;
	bool surprised;
	float vLastKnownPos[3];
	void *pLastKnownNode;
};

struct ai_suppression_t {
	int iTime;
	void *pSuppressor;
	float clipPlane[3];
	int movementOnly;
};

struct ActorSuppression {
	int ignoreSuppression;
	int suppressionWait;
	int suppressionDuration;
	int suppressionStartTime;
	float suppressionMeter;
};

struct ActorCombat {
	int ambushStartTime;
	int exposedStartTime;
	int exposedDuration;
	bool provideCoveringFire;
	bool doingAmbush;
	bool currentAmbushNodeInvalid;
	bool allAmbushNodesFailed;
	int combatMode;
	int alertLevel;
	bool damageShield;
	bool noGrenadeReturnThrow;
	bool noAttackerAccuracyMod;
	float frontShieldAngleCos;
};

struct potential_threat_t {
	bool isEnabled;
	float direction[2];
};

struct SentientHandle {
	unsigned __int16 number;
	unsigned __int16 infoIndex;
};

struct ActorSecondaryTarget {
	EntHandle entity;
	float dirToEnt[2];
	float distToEnt;
	void *node;
};


struct ActorThreat {
	bool hasThreateningEnemy;
	bool allEnemiesInSimilarDir;
	bool newEnemyReaction;
	bool ignoreExplosionEvents;
	bool bPacifist;
	int iPacifistWait;
	potential_threat_t potentialThreat;
	int threatUpdateTime;
	float footstepDetectDistSq;
	float footstepDetectDistWalkSq;
	float footstepDetectDistSprintSq;
	float reactionTargetPos[3];
	float newEnemyReactionDistSq;
	float highlyAwareRadius;
	SentientHandle pFavoriteEnemy;
	int numSecondaryTarget;
	ActorSecondaryTarget secondaryTargets[2];
};

struct ActorGrenade {
	float grenadeAwareness;
	int grenadeExistTime;
	EntHandle pGrenade;
	int iGrenadeWeapon;
	unsigned __int16 GrenadeTossMethod;
	bool bGrenadeTossValid;
	bool bGrenadeTargetValid;
	bool grenadeTossWithBounce;
	int iGrenadeAmmo;
	float vGrenadeTossPos[3];
	float vGrenadeTargetPos[3];
	float vGrenadeTossVel[3];
	float pickupPos[3];
};

struct ActorTurret {
	gentity_s *pTurret;
	unsigned __int16 turretAnim;
	char turretAnimSet;
};

struct scr_animscript_t {
	int func;
	int endFunc;
	unsigned __int16 name;
private:
	char __padding000[2];
};

struct actor_physics_t {
	float vOrigin[3];
	float vVelocity[3];
	unsigned __int16 groundEntNum;
	int iFootstepTimer;
	int bHasGroundPlane;
	float groundplaneSlope;
	int iSurfaceType;
	float vWishDelta[3];
	int bIsAlive;
	int iEntNum;
	int ePhysicsType;
	float fGravity;
	int iMsec;
	Bounds bounds;
	bool prone;
	bool stepMove;
	int iTraceMask;
	int foliageSoundTime;
	int iNumTouch;
	int iTouchEnts[32];
	int iHitEntnum;
	float vHitOrigin[2];
	float vHitNormal[2];
	char bStuck;
	char bDeflected;
	bool pathGoingDown;
	int stairsState;
};

struct ActorNavigation {
	float fWalkDist;
	float fWalkDistFacingMotion;
	bool isInBadPlace;
	char badplaceRecheckPathLen;
	float badPlaceAwareness;
};

struct pathpoint_t {
	float vOrigPoint[3];
	float fDir2D[2];
	float fOrigLength;
	int iNodeNum;
};


struct path_t {
	pathpoint_t pts[32];
	char wPathLen;
	char wOrigPathLen;
	char wDodgeCount;
	char wNegotiationStartNode;
	char lookaheadNextNode;
	char pathChangeNotifyNode;
	__int16 wDodgeEntity;
	float vFinalGoal[3];
	float vStartPos[3];
	float lookaheadDir[3];
	float lookaheadPos[3];
	float fLookaheadDist;
	float fLookaheadAmount;
	float fLookaheadDistToNextNode;
	int minLookAheadNodes;
	int flags;
	int iPathTime;
	int iPathClearedTime;
	int eTeam;
	float fCurrLength;
	float vCurrPoint[3];
	int iPathEndTime;
	float pathEndAnimDistSq;
	bool pathEndAnimNotified;
	bool lookaheadHitsStairs;
	bool useChokePoints;
	float pathChangeTracePos[2];
	int randomPercent;
};

struct path_trim_t {
	int iIndex;
	int iDelta;
};

struct actor_goal_s {
	float pos[3];
	float radius;
	float height;
	void *node;
	gentity_s *volume;
};


struct actor_s {
	gentity_s *ent;
	void *sentient;
	int species; //AISpecies
	int talkToSpecies;
	int eState[6]; //ai_state_t
	int eSubState[6]; //ai_substate_t
	unsigned int stateLevel;
	int iStateTime;
	int preThinkTime;
	ai_transition_cmd_t StateTransitions[13];
	unsigned int transitionCount;
	int eSimulatedState[6];
	unsigned int simulatedStateLevel;
	unsigned __int16 properName;
	unsigned __int16 weaponName;
	ActorShoot shoot;
	ActorOrientation orientation;
	ai_orient_t CodeOrient;
	ai_orient_t ScriptOrient;
	ActorPainDeath painDeath;
	ActorProne prone;
	actor_prone_info_s ProneInfo;
	ActorCachedInfo eyeInfo;
	ActorCachedInfo muzzleInfo;
	ActorLookAtInfo lookAtInfo;
	ActorDelayedWeaponDrop weapDrops[2];
	ActorCoverArrivalInfo arrivalInfo;
	ActorNodeSelect nodeSelect;
	ActorSight sight;
	sentient_info_t sentientInfo[50];
	ai_suppression_t Suppressant[4];
	ActorSuppression suppression;
	ActorCombat combat;
	ActorThreat threat;
	ActorGrenade grenade;
	ActorTurret turret;
	int eAllowedStances;
	unsigned __int16 AnimScriptHandle;
	scr_animscript_t *pAnimScriptFunc;
	scr_animscript_t *pPrevAnimScriptFunc;
	scr_animscript_t *pAttackScriptFunc;
	scr_animscript_t *pRequestedScript;
	scr_animscript_t AnimScriptSpecific;
	int eTraverseMode;
	char moveMode;
	bool useCombatScriptAtCover;
	bool prevAnimScriptTerminated;
	bool safeToChangeScript;
	bool bUseGoalWeight;
	bool bCanClimbLadders;
	int eAnimMode;
	int eScriptSetAnimMode;
	unsigned __int16 anim_pose;
	actor_physics_t Physics;
	ActorNavigation navigation;
	path_t Path;
	path_trim_t TrimInfo;
	float fInterval;
	int pathWaitTime;
	int iTeamMoveWaitTime;
	int iTeamMoveDodgeTime;
	int stoppedWaitStartTime;
	EntHandle stoppedWaitEnt;
	actor_s *pPileUpActor;
	gentity_s *pPileUpEnt;
	int bDontAvoidPlayer;
	float sideMove;
	bool noDodgeMove;
	int mayMoveTime;
	float nodeOffsetDist;
	float nodeOffsetPos[3];
	float prevMoveDir[2];
	float leanAmount;
	float turnRate;
	EntHandle pCloseEnt;
	int moveHistoryIndex;
	bool moveHistoryConsistent;
	float moveHistory[10][2];
	actor_goal_s codeGoal;
	int codeGoalSrc;
	actor_goal_s scriptGoal;
	EntHandle scriptGoalEnt;
	int scriptGoalEntLastUpdate;
	int scriptGoalEntUpdateInterval;
	float pathEnemyLookahead;
	float pathEnemyFightDist;
	float meleeAttackDist;
	bool useEnemyGoal;
	bool useMeleeAttackSpot;
	bool goalPosChanged;
	bool commitToFixedNode;
	bool ignoreForFixedNodeSafeCheck;
	bool fixedNode;
	float fixedNodeSafeRadius;
	float fixedNodeSafeVolumeRadiusSq;
	EntHandle fixedNodeSafeVolume;
	int bDropWeapon;
	int bDrawOnCompass;
	int iTraceCount;
	int iUseHintString;
	char useable;
	bool ignoreTriggers;
	bool pushable;
	bool script_pushable;
	bool inuse;
	int shieldHealth;
	unsigned __int16 shieldName;
	unsigned __int16 potentialCoverNode[10];
	unsigned __int16 potentialAmbushNode[32];
	const char *pszDebugInfo;
};


struct level_locals_t {
	gclient_s *clients;
	gentity_s *gentities;
	int num_entities;
	gentity_s *firstFreeEnt;
	gentity_s *lastFreeEnt;
	void *sentients;
	actor_s *actors;
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

struct scr_entref_t {
	unsigned __int16 entnum;
	unsigned __int16 classnum;
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

struct function_stack_t {
	const char *pos;
	unsigned int localId;
	unsigned int localVarCount;
	VariableValue *top;
	VariableValue *startTop;
};


struct function_frame_t {
	function_stack_t fs;
	int topType;
};


struct scrVmPub_t {
	unsigned int *localVars;
	VariableValue *maxstack;
	int function_count;
	function_frame_t *function_frame;
	VariableValue *top;
	unsigned int inparamcount;
	unsigned int outparamcount;
	function_frame_t function_frame_start[32];
	VariableValue stack[2048];
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




extern scrVmPub_t * scrVmPub;
extern gentity_s * g_entities;

