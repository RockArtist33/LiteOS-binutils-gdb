#as:
#objdump: -dr

.*:[    ]+file format .*


Disassembly of section .text:

00000000.* <.text>:
[ 	]+0:[ 	]+03400000[ 	]+[ 	]+andi[ 	]+\$zero, \$zero, 0x0
[ 	]+4:[ 	]+63fffc04[ 	]+[ 	]+blt[ 	]+\$zero, \$a0, -4\(0x3fffc\)[ 	]+# 0x0
[ 	]+8:[ 	]+67fff880[ 	]+[ 	]+bge[ 	]+\$a0, \$zero, -8\(0x3fff8\)[ 	]+# 0x0
[ 	]+c:[ 	]+67fff404[ 	]+[ 	]+bge[ 	]+\$zero, \$a0, -12\(0x3fff4\)[ 	]+# 0x0
[ 	]+10:[ 	]+43fff09f[ 	]+[ 	]+beqz[ 	]+\$a0, -16\(0x7ffff0\)[ 	]+# 0x0
[ 	]+14:[ 	]+47ffec9f[ 	]+[ 	]+bnez[ 	]+\$a0, -20\(0x7fffec\)[ 	]+# 0x0
[ 	]+18:[ 	]+4bffe81f[ 	]+[ 	]+bceqz[ 	]+\$fcc0, -24\(0x7fffe8\)[ 	]+# 0x0
[ 	]+1c:[ 	]+4bffe51f[ 	]+[ 	]+bcnez[ 	]+\$fcc0, -28\(0x7fffe4\)[ 	]+# 0x0
[ 	]+20:[ 	]+4c000080[ 	]+[ 	]+jirl[ 	]+\$zero, \$a0, 0
[ 	]+24:[ 	]+53ffdfff[ 	]+[ 	]+b[ 	]+-36\(0xfffffdc\)[ 	]+# 0x0
[ 	]+28:[ 	]+57ffdbff[ 	]+[ 	]+bl[ 	]+-40\(0xfffffd8\)[ 	]+# 0x0
[ 	]+2c:[ 	]+5bffd485[ 	]+[ 	]+beq[ 	]+\$a0, \$a1, -44\(0x3ffd4\)[ 	]+# 0x0
[ 	]+30:[ 	]+5fffd085[ 	]+[ 	]+bne[ 	]+\$a0, \$a1, -48\(0x3ffd0\)[ 	]+# 0x0
[ 	]+34:[ 	]+63ffcc85[ 	]+[ 	]+blt[ 	]+\$a0, \$a1, -52\(0x3ffcc\)[ 	]+# 0x0
[ 	]+38:[ 	]+63ffc8a4[ 	]+[ 	]+blt[ 	]+\$a1, \$a0, -56\(0x3ffc8\)[ 	]+# 0x0
[ 	]+3c:[ 	]+67ffc485[ 	]+[ 	]+bge[ 	]+\$a0, \$a1, -60\(0x3ffc4\)[ 	]+# 0x0
[ 	]+40:[ 	]+67ffc0a4[ 	]+[ 	]+bge[ 	]+\$a1, \$a0, -64\(0x3ffc0\)[ 	]+# 0x0
[ 	]+44:[ 	]+6bffbc85[ 	]+[ 	]+bltu[ 	]+\$a0, \$a1, -68\(0x3ffbc\)[ 	]+# 0x0
[ 	]+48:[ 	]+6bffb8a4[ 	]+[ 	]+bltu[ 	]+\$a1, \$a0, -72\(0x3ffb8\)[ 	]+# 0x0
[ 	]+4c:[ 	]+6fffb485[ 	]+[ 	]+bgeu[ 	]+\$a0, \$a1, -76\(0x3ffb4\)[ 	]+# 0x0
[ 	]+50:[ 	]+6fffb0a4[ 	]+[ 	]+bgeu[ 	]+\$a1, \$a0, -80\(0x3ffb0\)[ 	]+# 0x0
