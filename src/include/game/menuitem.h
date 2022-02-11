#ifndef IN_GAME_MENUITEM_H
#define IN_GAME_MENUITEM_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 menuitem0f0e5d2c(void);
s16 menuitem0f0e5ef8(s16 arg0, struct menuitem *item);
u32 menuitem0f0e6038(void);
Gfx *menuitemListOverlay(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2);
Gfx *menuitemListRender(Gfx *gdl, struct menurendercontext *context);
bool menuitemListTick(struct menuitem *item, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data);

void menuitemDropdownInit(struct menuitem *item, union menuitemdata *data);
Gfx *menuitemDropdownRender(Gfx *gdl);
bool menuitemDropdownTick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data);

Gfx *menuitemDropdownOverlay(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, struct menudialog *dialog, union menuitemdata *data);
bool menuitemKeyboardIsStringEmptyOrSpaces(char *text);
Gfx *menuitemKeyboardRender(Gfx *gdl, struct menurendercontext *thing);
bool menuitemKeyboardTick(struct menuitem *item, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data);
void menuitemKeyboardInit(struct menuitem *item, union menuitemdata *data);

Gfx *menuitemSeparatorRender(Gfx *gdl, struct menurendercontext *context);

Gfx *menuitemObjectiveRender(Gfx *gfx, struct menudialog *dialog, s32 index, s32 position, s32 x, s32 y, s32 width, s32 height, s32 arg8, s32 arg9);
Gfx *menuitemObjectivesRender(Gfx *gdl, struct menurendercontext *context);

Gfx *menuitemModelRender(Gfx *gdl, struct menurendercontext *context);

Gfx *menuitemLabelRender(Gfx *gdl, struct menurendercontext *context);

Gfx *menuitemMeterRender(Gfx *gdl, struct menurendercontext *context);

Gfx *menuitemSelectableRender(Gfx *gdl, struct menurendercontext *context);
bool menuitemSelectableTick(struct menuitem *item, struct menuinputs *inputs, u32 tickflags);

Gfx *menuitemSliderRender(Gfx *gdl);
bool menuitemSliderTick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data);
void menuitemSliderInit(union menuitemdata *data);

Gfx *menuitemCarouselRender(Gfx *gdl, struct menurendercontext *context);
bool menuitemCarouselTick(struct menuitem *item, struct menuinputs *inputs, u32 tickflags);

Gfx *menuitemCheckboxRender(Gfx *gdl, struct menurendercontext *context);
bool menuitemCheckboxTick(struct menuitem *item, struct menuinputs *inputs, u32 tickflags);

char *menuitemScrollableGetText(u32 type);
Gfx *menuitemScrollableRender(Gfx *gdl, struct menurendercontext *context);
bool menuitemScrollableTick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data);
void menuitemScrollableInit(union menuitemdata *data);

Gfx *menuitemMarqueeRender(Gfx *gdl, struct menurendercontext *context);
bool menuitemMarqueeTick(struct menuitem *item, union menuitemdata *data);
void menuitemMarqueeInit(union menuitemdata *data);

Gfx *menuitem07Render(Gfx *gdl);

Gfx *menuitemRankingRender(Gfx *gdl, struct menurendercontext *context);
bool menuitemRankingTick(struct menuinputs *inputs, u32 tickflags, union menuitemdata *data);
void menuitemRankingInit(union menuitemdata *data);

Gfx *menuitemPlayerStatsRender(Gfx *gdl, struct menurendercontext *context);
bool menuitemPlayerStatsTick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data);
Gfx *menuitemPlayerStatsOverlay(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, struct menudialog *dialog, union menuitemdata *data);
void menuitemPlayerStatsInit(struct menuitem *item, union menuitemdata *data);

u32 menuitem0f0ef394(void);
Gfx *menuitemControllerRenderTexture(Gfx *gdl, s32 x, s32 y, s32 texturenum, u32 alpha);
Gfx *menuitemControllerRenderLines(Gfx *gdl, struct menurendercontext *context, s32 arg2, s32 arg3, s32 x, s32 y, u32 alpha);
u16 menuitemControllerGetButtonAction(s32 mode, s32 buttonnum);
Gfx *menuitemControllerTextRender(Gfx *gdl, s32 curmode, struct menurendercontext *context, s32 x, s32 y, u32 valuecolour, u32 labelcolour, s8 prevmode);
Gfx *menuitemControllerInfoRender(Gfx *gdl, struct menurendercontext *context, s32 x, s32 y, s32 curmode, u32 alpha, u32 colour1, u32 colour2, s8 prevmode);
Gfx *menuitemControllerRender(Gfx *gdl, struct menurendercontext *context);
void menuitemControllerInit(union menuitemdata *data);

Gfx *menuitemRender(Gfx *gdl, struct menurendercontext *context);
bool menuitemTick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data);
void menuitemInit(struct menuitem *item, union menuitemdata *data);
Gfx *menuitemOverlay(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, struct menudialog *dialog, union menuitemdata *data);

#endif
