module Data.Bits.Extra

%foreign "C:rotate8L,endian"
prim__rotateBits8L : Bits8 -> Int -> Bits8

%foreign "C:rotate8R,endian"
prim__rotateBits8R : Bits8 -> Int -> Bits8

%foreign "C:rotate16L,endian"
prim__rotateBits16L : Bits16 -> Int -> Bits16

%foreign "C:rotate16R,endian"
prim__rotateBits16R : Bits16 -> Int -> Bits16

%foreign "C:rotate32L,endian"
prim__rotateBits32L : Bits32 -> Int -> Bits32

%foreign "C:rotate32R,endian"
prim__rotateBits32R : Bits32 -> Int -> Bits32

%foreign "C:rotate64L,endian"
prim__rotateBits64L : Bits64 -> Int -> Bits64

%foreign "C:rotate64R,endian"
prim__rotateBits64R : Bits64 -> Int -> Bits64

public export
rotateBit8L : Bits8 -> Int -> Bits8
rotateBit8L = prim__rotateBits8L

public export
rotateBit8R : Bits8 -> Int -> Bits8
rotateBit8R = prim__rotateBits8R

public export
rotateBit16L : Bits16 -> Int -> Bits16
rotateBit16L = prim__rotateBits16L

public export
rotateBit16R : Bits16 -> Int -> Bits16
rotateBit16R = prim__rotateBits16R

public export
rotateBit32L : Bits32 -> Int -> Bits32
rotateBit32L = prim__rotateBits32L

public export
rotateBit32R : Bits32 -> Int -> Bits32
rotateBit32R = prim__rotateBits32R

public export
rotateBit64L : Bits64 -> Int -> Bits64
rotateBit64L = prim__rotateBits64L

public export
rotateBit64R : Bits64 -> Int -> Bits64
rotateBit64R = prim__rotateBits64R

