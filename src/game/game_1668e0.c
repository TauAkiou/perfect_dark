#include <ultra64.h>
#include "constants.h"
#include "game/game_1668e0.h"
#include "bss.h"
#include "lib/lib_159b0.h"
#include "data.h"
#include "types.h"

u8 *var800a6660;
s16 *var800a6664; // room numbers
s16 *var800a6668;
f32 *var800a666c;
Mtxf *var800a6670;

s32 var80082050 = 0;

void currentPlayerSetLastRoomForOffset(s32 room)
{
	g_Vars.currentplayer->lastroomforoffset = room;
}

void func0f1668f0(s32 index, s32 roomnum)
{
	g_Rooms[roomnum].unk10 = index;
	var800a6664[index] = roomnum;
}

void func0f16692c(s32 index, s32 roomnum)
{
	g_Rooms[roomnum].unk10 = -1;
	var800a6664[index] = -1;
}

void func0f16696c(s32 index)
{
	if (var800a6664[index] != -1) {
		func0f16692c(index, var800a6664[index]);
	}

	var800a6660[index] = 2;
	var800a6668[index] = -1;
	var800a666c[index] = 1;
}

s32 func0f1669fc(void)
{
	s32 i;

	for (i = 0; i < var80082050; i++) {
		if (var800a6660[i] > 1 && var800a6668[i] == -1) {
			return i;
		}
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f166a6c
/*  f166a6c:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f166a70:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f166a74:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f166a78:	8cc204b4 */ 	lw	$v0,0x4b4($a2)
/*  f166a7c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f166a80:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f166a84:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f166a88:	0c00566c */ 	jal	func000159b0
/*  f166a8c:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f166a90:	3c013f80 */ 	lui	$at,0x3f80
/*  f166a94:	44810000 */ 	mtc1	$at,$f0
/*  f166a98:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f166a9c:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f166aa0:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f166aa4:	3c038008 */ 	lui	$v1,%hi(g_Stages)
/*  f166aa8:	2463fcc0 */ 	addiu	$v1,$v1,%lo(g_Stages)
/*  f166aac:	e4800000 */ 	swc1	$f0,0x0($a0)
/*  f166ab0:	e4800014 */ 	swc1	$f0,0x14($a0)
/*  f166ab4:	e4800028 */ 	swc1	$f0,0x28($a0)
/*  f166ab8:	846e05e8 */ 	lh	$t6,0x5e8($v1)
/*  f166abc:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f166ac0:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f166ac4:	104e000a */ 	beq	$v0,$t6,.L0f166af0
/*  f166ac8:	2401000f */ 	addiu	$at,$zero,0xf
/*  f166acc:	846f0738 */ 	lh	$t7,0x738($v1)
/*  f166ad0:	104f0007 */ 	beq	$v0,$t7,.L0f166af0
/*  f166ad4:	00000000 */ 	nop
/*  f166ad8:	84780118 */ 	lh	$t8,0x118($v1)
/*  f166adc:	10580004 */ 	beq	$v0,$t8,.L0f166af0
/*  f166ae0:	00000000 */ 	nop
/*  f166ae4:	84790000 */ 	lh	$t9,0x0($v1)
/*  f166ae8:	54590004 */ 	bnel	$v0,$t9,.L0f166afc
/*  f166aec:	846804d0 */ 	lh	$t0,0x4d0($v1)
.L0f166af0:
/*  f166af0:	10a1001d */ 	beq	$a1,$at,.L0f166b68
/*  f166af4:	00000000 */ 	nop
/*  f166af8:	846804d0 */ 	lh	$t0,0x4d0($v1)
.L0f166afc:
/*  f166afc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f166b00:	10480004 */ 	beq	$v0,$t0,.L0f166b14
/*  f166b04:	00000000 */ 	nop
/*  f166b08:	84690070 */ 	lh	$t1,0x70($v1)
/*  f166b0c:	54490004 */ 	bnel	$v0,$t1,.L0f166b20
/*  f166b10:	846a0620 */ 	lh	$t2,0x620($v1)
.L0f166b14:
/*  f166b14:	10a10014 */ 	beq	$a1,$at,.L0f166b68
/*  f166b18:	00000000 */ 	nop
/*  f166b1c:	846a0620 */ 	lh	$t2,0x620($v1)
.L0f166b20:
/*  f166b20:	24010001 */ 	addiu	$at,$zero,0x1
/*  f166b24:	104a0007 */ 	beq	$v0,$t2,.L0f166b44
/*  f166b28:	00000000 */ 	nop
/*  f166b2c:	846b0310 */ 	lh	$t3,0x310($v1)
/*  f166b30:	104b0004 */ 	beq	$v0,$t3,.L0f166b44
/*  f166b34:	00000000 */ 	nop
/*  f166b38:	846c07a8 */ 	lh	$t4,0x7a8($v1)
/*  f166b3c:	544c0004 */ 	bnel	$v0,$t4,.L0f166b50
/*  f166b40:	846d0700 */ 	lh	$t5,0x700($v1)
.L0f166b44:
/*  f166b44:	10a10008 */ 	beq	$a1,$at,.L0f166b68
/*  f166b48:	00000000 */ 	nop
/*  f166b4c:	846d0700 */ 	lh	$t5,0x700($v1)
.L0f166b50:
/*  f166b50:	3c03800a */ 	lui	$v1,%hi(g_BgRooms)
/*  f166b54:	24010071 */ 	addiu	$at,$zero,0x71
/*  f166b58:	144d0015 */ 	bne	$v0,$t5,.L0f166bb0
/*  f166b5c:	24634cc4 */ 	addiu	$v1,$v1,%lo(g_BgRooms)
/*  f166b60:	54a10014 */ 	bnel	$a1,$at,.L0f166bb4
/*  f166b64:	8c6a0000 */ 	lw	$t2,0x0($v1)
.L0f166b68:
/*  f166b68:	3c03800a */ 	lui	$v1,%hi(g_BgRooms)
/*  f166b6c:	24634cc4 */ 	addiu	$v1,$v1,%lo(g_BgRooms)
/*  f166b70:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f166b74:	00051080 */ 	sll	$v0,$a1,0x2
/*  f166b78:	00451021 */ 	addu	$v0,$v0,$a1
/*  f166b7c:	00021080 */ 	sll	$v0,$v0,0x2
/*  f166b80:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f166b84:	c5e40004 */ 	lwc1	$f4,0x4($t7)
/*  f166b88:	e4840030 */ 	swc1	$f4,0x30($a0)
/*  f166b8c:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f166b90:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f166b94:	c7260008 */ 	lwc1	$f6,0x8($t9)
/*  f166b98:	e4860034 */ 	swc1	$f6,0x34($a0)
/*  f166b9c:	8c680000 */ 	lw	$t0,0x0($v1)
/*  f166ba0:	01024821 */ 	addu	$t1,$t0,$v0
/*  f166ba4:	c528000c */ 	lwc1	$f8,0xc($t1)
/*  f166ba8:	10000019 */ 	b	.L0f166c10
/*  f166bac:	e4880038 */ 	swc1	$f8,0x38($a0)
.L0f166bb0:
/*  f166bb0:	8c6a0000 */ 	lw	$t2,0x0($v1)
.L0f166bb4:
/*  f166bb4:	00051080 */ 	sll	$v0,$a1,0x2
/*  f166bb8:	8ccc0284 */ 	lw	$t4,0x284($a2)
/*  f166bbc:	00451021 */ 	addu	$v0,$v0,$a1
/*  f166bc0:	00021080 */ 	sll	$v0,$v0,0x2
/*  f166bc4:	01425821 */ 	addu	$t3,$t2,$v0
/*  f166bc8:	c56a0004 */ 	lwc1	$f10,0x4($t3)
/*  f166bcc:	c5900038 */ 	lwc1	$f16,0x38($t4)
/*  f166bd0:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f166bd4:	e4920030 */ 	swc1	$f18,0x30($a0)
/*  f166bd8:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f166bdc:	8ccf0284 */ 	lw	$t7,0x284($a2)
/*  f166be0:	01a27021 */ 	addu	$t6,$t5,$v0
/*  f166be4:	c5c40008 */ 	lwc1	$f4,0x8($t6)
/*  f166be8:	c5e6003c */ 	lwc1	$f6,0x3c($t7)
/*  f166bec:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f166bf0:	e4880034 */ 	swc1	$f8,0x34($a0)
/*  f166bf4:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f166bf8:	8cc80284 */ 	lw	$t0,0x284($a2)
/*  f166bfc:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f166c00:	c72a000c */ 	lwc1	$f10,0xc($t9)
/*  f166c04:	c5100040 */ 	lwc1	$f16,0x40($t0)
/*  f166c08:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f166c0c:	e4920038 */ 	swc1	$f18,0x38($a0)
.L0f166c10:
/*  f166c10:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f166c14:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f166c18:	03e00008 */ 	jr	$ra
/*  f166c1c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f166c20
/*  f166c20:	0004c0c0 */ 	sll	$t8,$a0,0x3
/*  f166c24:	0304c021 */ 	addu	$t8,$t8,$a0
/*  f166c28:	3c0e800a */ 	lui	$t6,%hi(g_Rooms)
/*  f166c2c:	8dce4928 */ 	lw	$t6,%lo(g_Rooms)($t6)
/*  f166c30:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f166c34:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f166c38:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f166c3c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f166c40:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f166c44:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f166c48:	afa40068 */ 	sw	$a0,0x68($sp)
/*  f166c4c:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f166c50:	87300010 */ 	lh	$s0,0x10($t9)
/*  f166c54:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f166c58:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x284)
/*  f166c5c:	12020015 */ 	beq	$s0,$v0,.L0f166cb4
/*  f166c60:	3c0a800a */ 	lui	$t2,%hi(var800a6668)
/*  f166c64:	8d4a6668 */ 	lw	$t2,%lo(var800a6668)($t2)
/*  f166c68:	8d08a244 */ 	lw	$t0,%lo(g_Vars+0x284)($t0)
/*  f166c6c:	00105840 */ 	sll	$t3,$s0,0x1
/*  f166c70:	014b6021 */ 	addu	$t4,$t2,$t3
/*  f166c74:	858d0000 */ 	lh	$t5,0x0($t4)
/*  f166c78:	8d091700 */ 	lw	$t1,0x1700($t0)
/*  f166c7c:	3c0f800a */ 	lui	$t7,%hi(var800a666c)
/*  f166c80:	00107080 */ 	sll	$t6,$s0,0x2
/*  f166c84:	152d000b */ 	bne	$t1,$t5,.L0f166cb4
/*  f166c88:	00000000 */ 	nop
/*  f166c8c:	8def666c */ 	lw	$t7,%lo(var800a666c)($t7)
/*  f166c90:	3c018006 */ 	lui	$at,%hi(var8005ef10)
/*  f166c94:	c426ef10 */ 	lwc1	$f6,%lo(var8005ef10)($at)
/*  f166c98:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f166c9c:	c7040000 */ 	lwc1	$f4,0x0($t8)
/*  f166ca0:	3c0a800a */ 	lui	$t2,%hi(var800a6660)
/*  f166ca4:	46062032 */ 	c.eq.s	$f4,$f6
/*  f166ca8:	00000000 */ 	nop
/*  f166cac:	45010012 */ 	bc1t	.L0f166cf8
/*  f166cb0:	00000000 */ 	nop
.L0f166cb4:
/*  f166cb4:	12020003 */ 	beq	$s0,$v0,.L0f166cc4
/*  f166cb8:	02002025 */ 	or	$a0,$s0,$zero
/*  f166cbc:	0fc59a4b */ 	jal	func0f16692c
/*  f166cc0:	8fa50068 */ 	lw	$a1,0x68($sp)
.L0f166cc4:
/*  f166cc4:	0fc59a7f */ 	jal	func0f1669fc
/*  f166cc8:	00000000 */ 	nop
/*  f166ccc:	00408025 */ 	or	$s0,$v0,$zero
/*  f166cd0:	00402025 */ 	or	$a0,$v0,$zero
/*  f166cd4:	0fc59a3c */ 	jal	func0f1668f0
/*  f166cd8:	8fa50068 */ 	lw	$a1,0x68($sp)
/*  f166cdc:	3c19800a */ 	lui	$t9,%hi(var800a6660)
/*  f166ce0:	8f396660 */ 	lw	$t9,%lo(var800a6660)($t9)
/*  f166ce4:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x284)
/*  f166ce8:	3c0d800a */ 	lui	$t5,%hi(var800a6668)
/*  f166cec:	03304021 */ 	addu	$t0,$t9,$s0
/*  f166cf0:	10000006 */ 	b	.L0f166d0c
/*  f166cf4:	a1000000 */ 	sb	$zero,0x0($t0)
.L0f166cf8:
/*  f166cf8:	8d4a6660 */ 	lw	$t2,%lo(var800a6660)($t2)
/*  f166cfc:	02001025 */ 	or	$v0,$s0,$zero
/*  f166d00:	01505821 */ 	addu	$t3,$t2,$s0
/*  f166d04:	10000018 */ 	b	.L0f166d68
/*  f166d08:	a1600000 */ 	sb	$zero,0x0($t3)
.L0f166d0c:
/*  f166d0c:	8d8ca244 */ 	lw	$t4,%lo(g_Vars+0x284)($t4)
/*  f166d10:	8dad6668 */ 	lw	$t5,%lo(var800a6668)($t5)
/*  f166d14:	00107840 */ 	sll	$t7,$s0,0x1
/*  f166d18:	8d891700 */ 	lw	$t1,0x1700($t4)
/*  f166d1c:	01af7021 */ 	addu	$t6,$t5,$t7
/*  f166d20:	3c18800a */ 	lui	$t8,%hi(var800a666c)
/*  f166d24:	a5c90000 */ 	sh	$t1,0x0($t6)
/*  f166d28:	8f18666c */ 	lw	$t8,%lo(var800a666c)($t8)
/*  f166d2c:	3c018006 */ 	lui	$at,%hi(var8005ef10)
/*  f166d30:	c428ef10 */ 	lwc1	$f8,%lo(var8005ef10)($at)
/*  f166d34:	0010c880 */ 	sll	$t9,$s0,0x2
/*  f166d38:	03194021 */ 	addu	$t0,$t8,$t9
/*  f166d3c:	e5080000 */ 	swc1	$f8,0x0($t0)
/*  f166d40:	8fa50068 */ 	lw	$a1,0x68($sp)
/*  f166d44:	0fc59a9b */ 	jal	func0f166a6c
/*  f166d48:	27a40024 */ 	addiu	$a0,$sp,0x24
/*  f166d4c:	3c0b800a */ 	lui	$t3,%hi(var800a6670)
/*  f166d50:	8d6b6670 */ 	lw	$t3,%lo(var800a6670)($t3)
/*  f166d54:	00105180 */ 	sll	$t2,$s0,0x6
/*  f166d58:	27a40024 */ 	addiu	$a0,$sp,0x24
/*  f166d5c:	0c005815 */ 	jal	func00016054
/*  f166d60:	014b2821 */ 	addu	$a1,$t2,$t3
/*  f166d64:	02001025 */ 	or	$v0,$s0,$zero
.L0f166d68:
/*  f166d68:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f166d6c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f166d70:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*  f166d74:	03e00008 */ 	jr	$ra
/*  f166d78:	00000000 */ 	nop
);

Gfx *func0f166d7c(Gfx *gdl, s32 roomnum)
{
	s32 index = func0f166c20(roomnum);

	gSPMatrix(gdl++, &var800a6670[index], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	return gdl;
}

struct coord *func0f166dd0(s32 room)
{
	return &g_BgRooms[room].pos;
}

void func0f166df0(s32 room, struct coord *globaldrawworldoffset)
{
	globaldrawworldoffset->x = g_BgRooms[room].pos.x;
	globaldrawworldoffset->y = g_BgRooms[room].pos.y;
	globaldrawworldoffset->z = g_BgRooms[room].pos.z;
}
