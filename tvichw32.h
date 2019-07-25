/* ========================================================================
   =================    TVicHW32  DLL interface        ====================
   ==========            Shareware Version 4.0                  ===========
   ==========  Copyright (c) 1997,1998, 1999 Victor I.Ishikeev  ===========
   ========================================================================
   ==========         mail to tools@entechtaiwan.com            ===========
   ==========                 ivi@ufanet.ru                     ===========
   ==========         http://www.entechtaiwan.com/tools.htm     ===========
   ======================================================================== */


#ifndef __TVicHW32_H
#define __TVicHW32_H


#if defined(WIN32)

#define VICFN  __stdcall
#else
#define VICFN  __pascal far

#endif // defined(WIN32)

#ifdef __cplusplus
    extern "C" {
#endif

#define LPT_NOT_ACQUIRED         0
#define LPT_ACQUIRE_SUCCESS      1
#define LPT_ACQUIRE_REFUSED      2
#define LPT_ACQUIRE_BAD_PORT     3
#define LPT_ACQUIRE_NOT_OPENED   4

#define cmdIoAccess              0
#define cmdMemoryAccess          1
#define cmdBusMaster             2
#define cmdSpecialCycleMonitor   3
#define cmdWriteAndInvalidate    4
#define cmdPaletteSnoop          5
#define cmdParityErrorResponse   6
#define cmdWaitCycle             7
#define cmdSystemError           8
#define cmdFastBackToBack        9


#define PCI_TYPE0_ADDRESSES             6
#define PCI_TYPE1_ADDRESSES             2
#define PCI_TYPE2_ADDRESSES             5

typedef struct _PCI_COMMON_CONFIG {

    USHORT  VendorID;                   // (ro)
    USHORT  DeviceID;                   // (ro)
    USHORT  Command;                    // Device control
    USHORT  Status;
    UCHAR   RevisionID;                 // (ro)
    UCHAR   ProgIf;                     // (ro)
    UCHAR   SubClass;                   // (ro)
    UCHAR   BaseClass;                  // (ro)
    UCHAR   CacheLineSize;              // (ro+)
    UCHAR   LatencyTimer;               // (ro+)
    UCHAR   HeaderType;                 // (ro)
    UCHAR   BIST;                       // Built in self test

    union {

		//
        // Non - Bridge
        //

        struct PCI_HEADER_TYPE_0 {
            ULONG   BaseAddresses[PCI_TYPE0_ADDRESSES];
            ULONG   Reserved1[2];
            ULONG   ROMBaseAddress;
            ULONG   Reserved2[2];

            UCHAR   InterruptLine;      //
            UCHAR   InterruptPin;       // (ro)
            UCHAR   MinimumGrant;       // (ro)
            UCHAR   MaximumLatency;     // (ro)
        } type0;

        //
        // PCI to PCI Bridge
        //

        struct _PCI_HEADER_TYPE_1 {
            ULONG   BaseAddresses[PCI_TYPE1_ADDRESSES];
            UCHAR   PrimaryBus;
            UCHAR   SecondaryBus;
            UCHAR   SubordinateBus;
            UCHAR   SecondaryLatency;
            UCHAR   IOBase;
            UCHAR   IOLimit;
            USHORT  SecondaryStatus;
            USHORT  MemoryBase;
            USHORT  MemoryLimit;
            USHORT  PrefetchBase;
            USHORT  PrefetchLimit;
            ULONG   PrefetchBaseUpper32;
            ULONG   PrefetchLimitUpper32;
            USHORT  IOBaseUpper16;
            USHORT  IOLimitUpper16;
            UCHAR   CapabilitiesPtr;
            UCHAR   Reserved1[3];
            ULONG   ROMBaseAddress;
            UCHAR   InterruptLine;
            UCHAR   InterruptPin;
            USHORT  BridgeControl;
        } type1;

        //
        // PCI to CARDBUS Bridge
        //

        struct _PCI_HEADER_TYPE_2 {
            ULONG   SocketRegistersBaseAddress;
            UCHAR   CapabilitiesPtr;
            UCHAR   Reserved;
            USHORT  SecondaryStatus;
            UCHAR   PrimaryBus;
            UCHAR   SecondaryBus;
            UCHAR   SubordinateBus;
            UCHAR   SecondaryLatency;
            struct  {
                ULONG   Base;
                ULONG   Limit;
            }       Range[PCI_TYPE2_ADDRESSES-1];
            UCHAR   InterruptLine;
            UCHAR   InterruptPin;
            USHORT  BridgeControl;
        } type2;


        ULONG AsUlong;

	} u;

    UCHAR   DeviceSpecific[192];

} PCI_COMMON_CONFIG, * PPCI_COMMON_CONFIG;


#ifndef _TVIC_INTERNAL


typedef void   (__stdcall * TOnDelphiInterrupt)(HANDLE Component, WORD IRQNumber);
typedef void   (__stdcall * TKbHookHandler)(BYTE scan_code);
typedef void   (__stdcall * TKbDelphiHandler)(HANDLE Componen, BYTE scan_code);
typedef void   (__stdcall * TOnHWInterrupt)(USHORT IRQNumber);

//===== DMA buffer request ==

typedef struct _DMA_BUFFER_REQUEST {
	ULONG LengthOfBuffer;
	ULONG AlignMask;
	ULONG PhysDmaAddress;
	PVOID LinDmaAddress;
	ULONG PMemHandle;
	ULONG KernelDmaAddress;
} DMA_BUFFER_REQUEST, * PDMA_BUFFER_REQUEST;


typedef struct _FIFO_RECORD {
    ULONG  PortAddr;
    ULONG  NumPorts;
    UCHAR Buf[1];
} FIFO_RECORD, *PFIFO_RECORD;

typedef struct _FIFO_RECORDW {
    ULONG  PortAddr;
    ULONG   NumPorts;
    USHORT Buf[1];
} FIFO_RECORDW, *PFIFO_RECORDW;

typedef struct _FIFO_RECORDL {
    ULONG  PortAddr;
    ULONG    NumPorts;
    ULONG   Buf[1];
} FIFO_RECORDL, *PFIFO_RECORDL;


#define FIFOSIZE 1000

typedef struct _KEYBOARD_INPUT_DATA 
{
    USHORT UnitId;
    USHORT MakeCode;
    USHORT Flags;
    USHORT Reserved;
    ULONG ExtraInformation;
} KEYBOARD_INPUT_DATA, * PKEYBOARD_INPUT_DATA;



#endif  // _TVIC_INTERNAL

typedef struct _HDDInfo {

       DWORD      BufferSize;
       DWORD      DoubleTransfer;
       DWORD      ControllerType;
       DWORD      ECCMode;
       DWORD      SectorsPerInterrupt;
       DWORD      Cylinders;
       DWORD      Heads;
       DWORD      SectorsPerTrack;

	   char       Model[41];
       char       SerialNumber[21];
       char       Revision[9];

} HDDInfo, *pHDDInfo;


HANDLE  VICFN CloseTVicHW32(HANDLE HW32);
HANDLE  VICFN OpenTVicHW32(HANDLE HW32,
						   char * ServiceName,
						   char * EntryPoint);

BOOL    VICFN GetActiveHW(HANDLE HW32); 
		
BOOL    VICFN GetHardAccess(HANDLE);
void    VICFN SetHardAccess(HANDLE HW32, BOOL bNewValue);

UCHAR   VICFN GetPortByte(HANDLE HW32,ULONG PortAddr); 
void    VICFN SetPortByte(HANDLE HW32,ULONG PortAddr, UCHAR nNewValue);
USHORT  VICFN GetPortWord(HANDLE HW32,ULONG PortAddr);
void    VICFN SetPortWord(HANDLE HW32,ULONG PortAddr, USHORT nNewValue);
ULONG    VICFN GetPortLong(HANDLE HW32,ULONG PortAddr);
void    VICFN SetPortLong(HANDLE HW32,ULONG PortAddr, ULONG  nNewValue);

ULONG   VICFN MapPhysToLinear(HANDLE HW32,ULONG PhAddr, ULONG PhSize); 
void    VICFN UnmapMemory(HANDLE HW32,ULONG PhAddr, ULONG PhSize);

UCHAR   VICFN GetMem(HANDLE HW32, ULONG MappedAddr, ULONG Offset);
void    VICFN SetMem(HANDLE HW32, ULONG MappedAddr, ULONG Offset, UCHAR nNewValue);
USHORT  VICFN GetMemW(HANDLE HW32,ULONG MappedAddr, ULONG Offset);
void    VICFN SetMemW(HANDLE HW32,ULONG MappedAddr, ULONG Offset, USHORT nNewValue);
ULONG   VICFN GetMemL(HANDLE HW32,ULONG MappedAddr, ULONG Offset);
void    VICFN SetMemL(HANDLE HW32,ULONG MappedAddr, ULONG Offset, ULONG nNewValue);

PVOID   VICFN GetLockedMemory(HANDLE HW32);

BOOL    VICFN IsIRQMasked(HANDLE HW32, USHORT IRQNumber); 
void    VICFN UnmaskIRQ(HANDLE HW32, USHORT IRQNumber, TOnHWInterrupt HWHandler); 
void    VICFN UnmaskDelphiIRQ(HANDLE HW32, HANDLE Component, USHORT IRQNumber, TOnHWInterrupt HWHandler); 
ULONG   VICFN MaskIRQ(HANDLE HW32, USHORT IRQNumber); 
ULONG   VICFN GetIRQCounter(HANDLE HW32, USHORT IRQNumber);

void    VICFN UnmaskIRQWithSharing(HANDLE HW32, USHORT IRQNumber, TOnHWInterrupt HWHandler, ULONG IrqShared);
void    VICFN UnmaskDelphiIRQWithSharing(HANDLE HW32, HANDLE Component, USHORT IRQNumber, TOnHWInterrupt HWHandler, ULONG IrqShared);

void    VICFN HookKeyboard(HANDLE HW32, TKbHookHandler HWHandler);
void    VICFN HookDelphiKeyboard(HANDLE HW32, HANDLE Component, TKbHookHandler HWHandler);
void    VICFN UnhookKeyboard(HANDLE HW32);
void    VICFN PutScanCode(HANDLE HW32,UCHAR b);
WORD    VICFN GetScanCode(HANDLE HW32);
void    VICFN PulseKeyboard(HANDLE HW32);
void    VICFN PulseKeyboardLocal(HANDLE HW32);

UCHAR   VICFN GetLPTNumber(HANDLE HW32);
void    VICFN SetLPTNumber(HANDLE HW32,UCHAR nNewValue);
UCHAR   VICFN GetLPTNumPorts(HANDLE HW32);
ULONG   VICFN GetLPTBasePort(HANDLE HW32);

BOOL    VICFN GetPin(HANDLE HW32,UCHAR nPin);
void    VICFN SetPin(HANDLE HW32,UCHAR nPin, BOOL bNewValue);

BOOL    VICFN GetLPTAckwl(HANDLE HW32);
BOOL    VICFN GetLPTBusy(HANDLE HW32);
BOOL    VICFN GetLPTPaperEnd(HANDLE HW32);
BOOL    VICFN GetLPTSlct(HANDLE HW32);
BOOL    VICFN GetLPTError(HANDLE HW32); 

void    VICFN LPTInit(HANDLE HW32);
void    VICFN LPTSlctIn(HANDLE HW32);
void    VICFN LPTStrobe(HANDLE HW32);
void    VICFN LPTAutofd(HANDLE HW32,BOOL Flag);

BOOL    VICFN LPTPrintChar(HANDLE HW32, UCHAR ch);

void    VICFN ForceIrqLPT(HANDLE HW32,BOOL IrqEnable);

void    VICFN SetLPTReadMode(HANDLE HW32);
void    VICFN SetLPTWriteMode(HANDLE HW32);


ULONG   VICFN DebugCode(HANDLE HW32);

void  VICFN ReadPortFIFO ( HANDLE         HW32,
						   PFIFO_RECORD   pPortRec);
                           
void  VICFN ReadPortWFIFO( HANDLE         HW32,
						   PFIFO_RECORDW  pPortRec);
                           
void  VICFN ReadPortLFIFO( HANDLE         HW32,
						   PFIFO_RECORDL  pPortRec);
                           
void  VICFN WritePortFIFO ( HANDLE        HW32,
						    PFIFO_RECORD  pPortRec);
                           
void  VICFN WritePortWFIFO( HANDLE        HW32,
							PFIFO_RECORDW pPortRec);
                           
void  VICFN WritePortLFIFO( HANDLE        HW32,
						    PFIFO_RECORDL pPortRec);
                           

void  VICFN GetHDDInfo(HANDLE   HW32,
					   USHORT   IdeNumber, 
					   USHORT   Master,
					   pHDDInfo Info);


USHORT VICFN GetLastPciBus(HANDLE HW32);
USHORT VICFN GetHardwareMechanism(HANDLE HW32);

BOOL   VICFN GetPciDeviceInfo( HANDLE              HW32,
	    					   USHORT              BusNum,
							   USHORT              DeviceNum,
                               USHORT              FuncNum,
                               PPCI_COMMON_CONFIG  pPciCfg);


BOOL   VICFN GetSysDmaBuffer( HANDLE                HW32,
	 					      DMA_BUFFER_REQUEST  * BufReq);

BOOL   VICFN GetBusmasterDmaBuffer( HANDLE              HW32,
	 					            PDMA_BUFFER_REQUEST BufReq);

void   VICFN FreeDmaBuffer( HANDLE              HW32,
	 			      	    PDMA_BUFFER_REQUEST BufReq);

USHORT VICFN AcquireLPT    ( HANDLE HW32, USHORT LPTNumber);

void   VICFN ReleaseLPT    ( HANDLE HW32, USHORT LPTNumber);			      

USHORT VICFN IsLPTAcquired ( HANDLE HW32, USHORT LPTNumber);			      

HANDLE VICFN OpenPciDeviceOnSlot( HANDLE HW32,
							      USHORT BusNum,
							      USHORT DeviceNum,
                                  USHORT FuncNum);

void   VICFN ClosePciDevice ( HANDLE HW32, HANDLE PciDevice);

USHORT VICFN ReadPciCommandReg ( HANDLE HW32, HANDLE PciDevice);
void   VICFN WritePciCommandReg ( HANDLE HW32, HANDLE PciDevice, USHORT CommandRegValue);

void   VICFN ControlPciCommandRegBits ( HANDLE HW32, 
									    HANDLE PciDevice, 
										BYTE   CommandRegBit,
										BYTE   SetClearFlag);

void  VICFN GetDosMemory( HANDLE  HW32,
						  WORD    SizeInBytes,
	 					  WORD  * Segment,
						  WORD  * Offset,
						  PVOID * Linear,
						  WORD  * BytesReturned);

void  VICFN FreeDosMemory( HANDLE  HW32,
						   WORD    Segment);
						  
void  VICFN MakeDirectory( HANDLE  HW32,
						   WORD    Segment);

#ifdef __cplusplus
	}
#endif

#endif
