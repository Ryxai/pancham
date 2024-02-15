module Network.Endian

%foreign "C:isLittleEndian,endian"
prim__isLittleEndian : Int

%foreign "C:hostToNetwork32,endian"
prim__hostToNetwork32: Bits32 -> Bits32

%foreign "C:networkToHost32,endian"
prim__networkToHost32: Bits32 -> Bits32

%foreign "C:hostToNetwork16,endian"
prim__hostToNetwork16: Bits16 -> Bits16

%foreign "C:networkToHost16,endian"
prim__networkToHost16: Bits16 -> Bits16

%foreign "C:hostToNetwork64,endian"
prim__hostToNetwork64: Bits64 -> Bits64

%foreign "C:networkToHost64,endian"
prim__networkToHost64: Bits64 -> Bits64

public export
isLittleEndian : Bool
isLittleEndian = (prim__isLittleEndian) == 1 

public export

interface NetworkOrdered a where
  hostToNetwork : a -> a
  networkToHost : a -> a

NetworkOrdered Bits8 where
  hostToNetwork x = x
  networkToHost x = x

NetworkOrdered Bits16 where
  hostToNetwork x = prim__hostToNetwork16 x
  networkToHost x = prim__networkToHost16 x

NetworkOrdered Bits32 where
  hostToNetwork x = prim__hostToNetwork32 x
  networkToHost x = prim__networkToHost32 x

NetworkOrdered Bits64 where
  hostToNetwork x = prim__hostToNetwork64 x
  networkToHost x = prim__networkToHost64 x

NetworkOrdered Int8 where
  hostToNetwork x = x
  networkToHost x = x

NetworkOrdered Int16 where
  hostToNetwork x = cast $ prim__hostToNetwork16 (cast x)
  networkToHost x = cast $ prim__networkToHost16 (cast x)

NetworkOrdered Int32 where
  hostToNetwork x = cast $ prim__hostToNetwork32 (cast x)
  networkToHost x = cast $ prim__networkToHost32 (cast x)

NetworkOrdered Int64 where
  hostToNetwork x = cast $ prim__hostToNetwork64 (cast x)
  networkToHost x = cast $ prim__networkToHost64 (cast x)

NetworkOrdered Char where
  hostToNetwork x = x
  networkToHost x = x








