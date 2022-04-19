//+---------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 1992 - 1997.
//
//  File:       oleauto.h
//
//  Contents:   Defines Ole Automation support function prototypes, constants
//
//----------------------------------------------------------------------------

#if !defined( _OLEAUTO_H_ )
#define _OLEAUTO_H_

// Set packing to 8 for ISV, and Win95 support
#ifndef RC_INVOKED
#include <pshpack8.h>
#endif // RC_INVOKED

//  Definition of the OLE Automation APIs, and macros.

#ifdef _OLEAUT32_
#define WINOLEAUTAPI        STDAPI
#define WINOLEAUTAPI_(type) STDAPI_(type)
#else
#define WINOLEAUTAPI        EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE
#define WINOLEAUTAPI_(type) EXTERN_C DECLSPEC_IMPORT type STDAPICALLTYPE
#endif

EXTERN_C const IID IID_StdOle;

#define STDOLE_MAJORVERNUM  0x1
#define STDOLE_MINORVERNUM  0x0
#define STDOLE_LCID         0x0000

// Version # of stdole2.tlb
#define STDOLE2_MAJORVERNUM 0x2
#define STDOLE2_MINORVERNUM 0x0
#define STDOLE2_LCID        0x0000

/* if not already picked up from olenls.h */
#ifndef _LCID_DEFINED
typedef DWORD LCID;
# define _LCID_DEFINED
#endif

#ifndef BEGIN_INTERFACE
#define BEGIN_INTERFACE
#define END_INTERFACE
#endif

/* pull in the MIDL generated header */
#include <oaidl.h>


/*---------------------------------------------------------------------*/
/*                            BSTR API                                 */
/*---------------------------------------------------------------------*/

WINOLEAUTAPI_(BSTR) SysAllocString(const OLECHAR *);
WINOLEAUTAPI_(INT)  SysReAllocString(BSTR *, const OLECHAR *);
WINOLEAUTAPI_(BSTR) SysAllocStringLen(const OLECHAR *, UINT);
WINOLEAUTAPI_(INT)  SysReAllocStringLen(BSTR *, const OLECHAR *, UINT);
WINOLEAUTAPI_(void) SysFreeString(BSTR);
WINOLEAUTAPI_(UINT) SysStringLen(BSTR);

#ifdef _WIN32
WINOLEAUTAPI_(UINT) SysStringByteLen(BSTR bstr);
WINOLEAUTAPI_(BSTR) SysAllocStringByteLen(LPCSTR psz, UINT len);
#endif

/*---------------------------------------------------------------------*/
/*                            Time API                                 */
/*---------------------------------------------------------------------*/

WINOLEAUTAPI_(INT) DosDateTimeToVariantTime(USHORT wDosDate, USHORT wDosTime, DOUBLE * pvtime);

WINOLEAUTAPI_(INT) VariantTimeToDosDateTime(DOUBLE vtime, USHORT * pwDosDate, USHORT * pwDosTime);

#ifdef _WIN32
WINOLEAUTAPI_(INT) SystemTimeToVariantTime(LPSYSTEMTIME lpSystemTime, DOUBLE *pvtime);
WINOLEAUTAPI_(INT) VariantTimeToSystemTime(DOUBLE vtime, LPSYSTEMTIME lpSystemTime);
#endif


/*---------------------------------------------------------------------*/
/*                          SafeArray API                              */
/*---------------------------------------------------------------------*/

WINOLEAUTAPI SafeArrayAllocDescriptor(UINT cDims, SAFEARRAY ** ppsaOut);
WINOLEAUTAPI SafeArrayAllocDescriptorEx(VARTYPE vt, UINT cDims, SAFEARRAY ** ppsaOut);
WINOLEAUTAPI SafeArrayAllocData(SAFEARRAY * psa);
WINOLEAUTAPI_(SAFEARRAY *) SafeArrayCreate(VARTYPE vt, UINT cDims, SAFEARRAYBOUND * rgsabound);
WINOLEAUTAPI_(SAFEARRAY *) SafeArrayCreateEx(VARTYPE vt, UINT cDims, SAFEARRAYBOUND * rgsabound, PVOID pvExtra);
WINOLEAUTAPI SafeArrayCopyData(SAFEARRAY *psaSource, SAFEARRAY *psaTarget);
WINOLEAUTAPI SafeArrayDestroyDescriptor(SAFEARRAY * psa);
WINOLEAUTAPI SafeArrayDestroyData(SAFEARRAY * psa);
WINOLEAUTAPI SafeArrayDestroy(SAFEARRAY * psa);
WINOLEAUTAPI SafeArrayRedim(SAFEARRAY * psa, SAFEARRAYBOUND * psaboundNew);
WINOLEAUTAPI_(UINT) SafeArrayGetDim(SAFEARRAY * psa);
WINOLEAUTAPI_(UINT) SafeArrayGetElemsize(SAFEARRAY * psa);
WINOLEAUTAPI SafeArrayGetUBound(SAFEARRAY * psa, UINT nDim, LONG * plUbound);
WINOLEAUTAPI SafeArrayGetLBound(SAFEARRAY * psa, UINT nDim, LONG * plLbound);
WINOLEAUTAPI SafeArrayLock(SAFEARRAY * psa);
WINOLEAUTAPI SafeArrayUnlock(SAFEARRAY * psa);
WINOLEAUTAPI SafeArrayAccessData(SAFEARRAY * psa, void HUGEP** ppvData);
WINOLEAUTAPI SafeArrayUnaccessData(SAFEARRAY * psa);
WINOLEAUTAPI SafeArrayGetElement(SAFEARRAY * psa, LONG * rgIndices, void * pv);
WINOLEAUTAPI SafeArrayPutElement(SAFEARRAY * psa, LONG * rgIndices, void * pv);
WINOLEAUTAPI SafeArrayCopy(SAFEARRAY * psa, SAFEARRAY ** ppsaOut);
WINOLEAUTAPI SafeArrayPtrOfIndex(SAFEARRAY * psa, LONG * rgIndices, void ** ppvData);
WINOLEAUTAPI SafeArraySetRecordInfo(SAFEARRAY * psa, IRecordInfo * prinfo);
WINOLEAUTAPI SafeArrayGetRecordInfo(SAFEARRAY * psa, IRecordInfo ** prinfo);
WINOLEAUTAPI SafeArraySetIID(SAFEARRAY * psa, REFGUID guid);
WINOLEAUTAPI SafeArrayGetIID(SAFEARRAY * psa, GUID * pguid);
WINOLEAUTAPI SafeArrayGetVartype(SAFEARRAY * psa, VARTYPE * pvt);
WINOLEAUTAPI_(SAFEARRAY *) SafeArrayCreateVector(VARTYPE vt, LONG lLbound, ULONG cElements);
WINOLEAUTAPI_(SAFEARRAY *) SafeArrayCreateVectorEx(VARTYPE vt, LONG lLbound, ULONG cElements, PVOID pvExtra);

/*---------------------------------------------------------------------*/
/*                           VARIANT API                               */
/*---------------------------------------------------------------------*/

WINOLEAUTAPI_(void) VariantInit(VARIANTARG * pvarg);
WINOLEAUTAPI VariantClear(VARIANTARG * pvarg);
WINOLEAUTAPI VariantCopy(VARIANTARG * pvargDest, VARIANTARG * pvargSrc);
WINOLEAUTAPI VariantCopyInd(VARIANT * pvarDest, VARIANTARG * pvargSrc);
WINOLEAUTAPI VariantChangeType(VARIANTARG * pvargDest,
                VARIANTARG * pvarSrc, USHORT wFlags, VARTYPE vt);
WINOLEAUTAPI VariantChangeTypeEx(VARIANTARG * pvargDest,
                VARIANTARG * pvarSrc, LCID lcid, USHORT wFlags, VARTYPE vt);

// Flags for VariantChangeType/VariantChangeTypeEx
#define VARIANT_NOVALUEPROP      0x01
#define VARIANT_ALPHABOOL        0x02 // For VT_BOOL to VT_BSTR conversions,
                                      // convert to "True"/"False" instead of
                                      // "-1"/"0"
#define VARIANT_NOUSEROVERRIDE   0x04 // For conversions to/from VT_BSTR,
				      // passes LOCALE_NOUSEROVERRIDE
				      // to core coercion routines
#define VARIANT_CALENDAR_HIJRI   0x08
#define VARIANT_LOCALBOOL        0x10 // For VT_BOOL to VT_BSTR and back,
                                      // convert to local language rather than
                                      // English

/*---------------------------------------------------------------------*/
/*                Vector <-> Bstr conversion APIs                      */
/*---------------------------------------------------------------------*/

WINOLEAUTAPI VectorFromBstr (BSTR bstr, SAFEARRAY ** ppsa);
WINOLEAUTAPI BstrFromVector (SAFEARRAY *psa, BSTR *pbstr);

/*---------------------------------------------------------------------*/
/*                     Variant API Flags                               */
/*---------------------------------------------------------------------*/

/* Any of the coersion functions that converts either from or to a string
 * takes an additional lcid and dwFlags arguments. The lcid argument allows
 * locale specific parsing to occur.  The dwFlags allow additional function
 * specific condition to occur.  All function that accept the dwFlags argument
 * can include either 0 or LOCALE_NOUSEROVERRIDE flag.
 */

/* The VarDateFromStr and VarBstrFromDate functions also accept the
 * VAR_TIMEVALUEONLY and VAR_DATEVALUEONLY flags
 */
#define VAR_TIMEVALUEONLY       ((DWORD)0x00000001)    /* return time value */
#define VAR_DATEVALUEONLY       ((DWORD)0x00000002)    /* return date value */

/* VarDateFromUdate() only */
#define VAR_VALIDDATE           ((DWORD)0x00000004)

/* Accepted by all date & format APIs */
#define VAR_CALENDAR_HIJRI      ((DWORD)0x00000008)    /* use Hijri calender */

/* Booleans can optionally be accepted in localized form. Pass VAR_LOCALBOOL
 * into VarBoolFromStr and VarBstrFromBool to use localized boolean names
 */
#define VAR_LOCALBOOL           ((DWORD)0x00000010)

/* When passed into VarFormat and VarFormatFromTokens, prevents substitution
 * of formats in the case where a string is passed in that can not be
 * coverted into the desired type. (for ex, 'Format("Hello", "General Number")')
 */
#define VAR_FORMAT_NOSUBSTITUTE ((DWORD)0x00000020)

/*
 * For VarBstrFromDate only - forces years to be 4 digits rather than shortening
 * to 2-digits when the years is in the date window.
 */
#define VAR_FOURDIGITYEARS	((DWORD)0x00000040)

/*---------------------------------------------------------------------*/
/*                     VARTYPE Coercion API                            */
/*---------------------------------------------------------------------*/

/* Note: The routines that convert *from* a string are defined
 * to take a OLECHAR* rather than a BSTR because no allocation is
 * required, and this makes the routines a bit more generic.
 * They may of course still be passed a BSTR as the strIn param.
 */

WINOLEAUTAPI VarUI1FromI2(SHORT sIn, BYTE * pbOut);
WINOLEAUTAPI VarUI1FromI4(LONG lIn, BYTE * pbOut);
WINOLEAUTAPI VarUI1FromR4(FLOAT fltIn, BYTE * pbOut);
WINOLEAUTAPI VarUI1FromR8(DOUBLE dblIn, BYTE * pbOut);
WINOLEAUTAPI VarUI1FromCy(CY cyIn, BYTE * pbOut);
WINOLEAUTAPI VarUI1FromDate(DATE dateIn, BYTE * pbOut);
WINOLEAUTAPI VarUI1FromStr(OLECHAR * strIn, LCID lcid, ULONG dwFlags, BYTE * pbOut);
WINOLEAUTAPI VarUI1FromDisp(IDispatch * pdispIn, LCID lcid, BYTE * pbOut);
WINOLEAUTAPI VarUI1FromBool(VARIANT_BOOL boolIn, BYTE * pbOut);
WINOLEAUTAPI VarUI1FromI1(CHAR cIn, BYTE *pbOut);
WINOLEAUTAPI VarUI1FromUI2(USHORT uiIn, BYTE *pbOut);
WINOLEAUTAPI VarUI1FromUI4(ULONG ulIn, BYTE *pbOut);
WINOLEAUTAPI VarUI1FromDec(DECIMAL *pdecIn, BYTE *pbOut);

WINOLEAUTAPI VarI2FromUI1(BYTE bIn, SHORT * psOut);
WINOLEAUTAPI VarI2FromI4(LONG lIn, SHORT * psOut);
WINOLEAUTAPI VarI2FromR4(FLOAT fltIn, SHORT * psOut);
WINOLEAUTAPI VarI2FromR8(DOUBLE dblIn, SHORT * psOut);
WINOLEAUTAPI VarI2FromCy(CY cyIn, SHORT * psOut);
WINOLEAUTAPI VarI2FromDate(DATE dateIn, SHORT * psOut);
WINOLEAUTAPI VarI2FromStr(OLECHAR * strIn, LCID lcid, ULONG dwFlags, SHORT * psOut);
WINOLEAUTAPI VarI2FromDisp(IDispatch * pdispIn, LCID lcid, SHORT * psOut);
WINOLEAUTAPI VarI2FromBool(VARIANT_BOOL boolIn, SHORT * psOut);
WINOLEAUTAPI VarI2FromI1(CHAR cIn, SHORT *psOut);
WINOLEAUTAPI VarI2FromUI2(USHORT uiIn, SHORT *psOut);
WINOLEAUTAPI VarI2FromUI4(ULONG ulIn, SHORT *psOut);
WINOLEAUTAPI VarI2FromDec(DECIMAL *pdecIn, SHORT *psOut);

WINOLEAUTAPI VarI4FromUI1(BYTE bIn, LONG * plOut);
WINOLEAUTAPI VarI4FromI2(SHORT sIn, LONG * plOut);
WINOLEAUTAPI VarI4FromR4(FLOAT fltIn, LONG * plOut);
WINOLEAUTAPI VarI4FromR8(DOUBLE dblIn, LONG * plOut);
WINOLEAUTAPI VarI4FromCy(CY cyIn, LONG * plOut);
WINOLEAUTAPI VarI4FromDate(DATE dateIn, LONG * plOut);
WINOLEAUTAPI VarI4FromStr(OLECHAR * strIn, LCID lcid, ULONG dwFlags, LONG * plOut);
WINOLEAUTAPI VarI4FromDisp(IDispatch * pdispIn, LCID lcid, LONG * plOut);
WINOLEAUTAPI VarI4FromBool(VARIANT_BOOL boolIn, LONG * plOut);
WINOLEAUTAPI VarI4FromI1(CHAR cIn, LONG *plOut);
WINOLEAUTAPI VarI4FromUI2(USHORT uiIn, LONG *plOut);
WINOLEAUTAPI VarI4FromUI4(ULONG ulIn, LONG *plOut);
WINOLEAUTAPI VarI4FromDec(DECIMAL *pdecIn, LONG *plOut);
WINOLEAUTAPI VarI4FromInt(INT intIn, LONG *plOut);

WINOLEAUTAPI VarR4FromUI1(BYTE bIn, FLOAT * pfltOut);
WINOLEAUTAPI VarR4FromI2(SHORT sIn, FLOAT * pfltOut);
WINOLEAUTAPI VarR4FromI4(LONG lIn, FLOAT * pfltOut);
WINOLEAUTAPI VarR4FromR8(DOUBLE dblIn, FLOAT * pfltOut);
WINOLEAUTAPI VarR4FromCy(CY cyIn, FLOAT * pfltOut);
WINOLEAUTAPI VarR4FromDate(DATE dateIn, FLOAT * pfltOut);
WINOLEAUTAPI VarR4FromStr(OLECHAR * strIn, LCID lcid, ULONG dwFlags, FLOAT *pfltOut);
WINOLEAUTAPI VarR4FromDisp(IDispatch * pdispIn, LCID lcid, FLOAT * pfltOut);
WINOLEAUTAPI VarR4FromBool(VARIANT_BOOL boolIn, FLOAT * pfltOut);
WINOLEAUTAPI VarR4FromI1(CHAR cIn, FLOAT *pfltOut);
WINOLEAUTAPI VarR4FromUI2(USHORT uiIn, FLOAT *pfltOut);
WINOLEAUTAPI VarR4FromUI4(ULONG ulIn, FLOAT *pfltOut);
WINOLEAUTAPI VarR4FromDec(DECIMAL *pdecIn, FLOAT *pfltOut);

WINOLEAUTAPI VarR8FromUI1(BYTE bIn, DOUBLE * pdblOut);
WINOLEAUTAPI VarR8FromI2(SHORT sIn, DOUBLE * pdblOut);
WINOLEAUTAPI VarR8FromI4(LONG lIn, DOUBLE * pdblOut);
WINOLEAUTAPI VarR8FromR4(FLOAT fltIn, DOUBLE * pdblOut);
WINOLEAUTAPI VarR8FromCy(CY cyIn, DOUBLE * pdblOut);
WINOLEAUTAPI VarR8FromDate(DATE dateIn, DOUBLE * pdblOut);
WINOLEAUTAPI VarR8FromStr(OLECHAR *strIn, LCID lcid, ULONG dwFlags, DOUBLE *pdblOut);
WINOLEAUTAPI VarR8FromDisp(IDispatch * pdispIn, LCID lcid, DOUBLE * pdblOut);
WINOLEAUTAPI VarR8FromBool(VARIANT_BOOL boolIn, DOUBLE * pdblOut);
WINOLEAUTAPI VarR8FromI1(CHAR cIn, DOUBLE *pdblOut);
WINOLEAUTAPI VarR8FromUI2(USHORT uiIn, DOUBLE *pdblOut);
WINOLEAUTAPI VarR8FromUI4(ULONG ulIn, DOUBLE *pdblOut);
WINOLEAUTAPI VarR8FromDec(DECIMAL *pdecIn, DOUBLE *pdblOut);

WINOLEAUTAPI VarDateFromUI1(BYTE bIn, DATE * pdateOut);
WINOLEAUTAPI VarDateFromI2(SHORT sIn, DATE * pdateOut);
WINOLEAUTAPI VarDateFromI4(LONG lIn, DATE * pdateOut);
WINOLEAUTAPI VarDateFromR4(FLOAT fltIn, DATE * pdateOut);
WINOLEAUTAPI VarDateFromR8(DOUBLE dblIn, DATE * pdateOut);
WINOLEAUTAPI VarDateFromCy(CY cyIn, DATE * pdateOut);
WINOLEAUTAPI VarDateFromStr(OLECHAR *strIn, LCID lcid, ULONG dwFlags, DATE *pdateOut);
WINOLEAUTAPI VarDateFromDisp(IDispatch * pdispIn, LCID lcid, DATE * pdateOut);
WINOLEAUTAPI VarDateFromBool(VARIANT_BOOL boolIn, DATE * pdateOut);
WINOLEAUTAPI VarDateFromI1(CHAR cIn, DATE *pdateOut);
WINOLEAUTAPI VarDateFromUI2(USHORT uiIn, DATE *pdateOut);
WINOLEAUTAPI VarDateFromUI4(ULONG ulIn, DATE *pdateOut);
WINOLEAUTAPI VarDateFromDec(DECIMAL *pdecIn, DATE *pdateOut);

WINOLEAUTAPI VarCyFromUI1(BYTE bIn, CY * pcyOut);
WINOLEAUTAPI VarCyFromI2(SHORT sIn, CY * pcyOut);
WINOLEAUTAPI VarCyFromI4(LONG lIn, CY * pcyOut);
WINOLEAUTAPI VarCyFromR4(FLOAT fltIn, CY * pcyOut);
WINOLEAUTAPI VarCyFromR8(DOUBLE dblIn, CY * pcyOut);
WINOLEAUTAPI VarCyFromDate(DATE dateIn, CY * pcyOut);
WINOLEAUTAPI VarCyFromStr(OLECHAR * strIn, LCID lcid, ULONG dwFlags, CY * pcyOut);
WINOLEAUTAPI VarCyFromDisp(IDispatch * pdispIn, LCID lcid, CY * pcyOut);
WINOLEAUTAPI VarCyFromBool(VARIANT_BOOL boolIn, CY * pcyOut);
WINOLEAUTAPI VarCyFromI1(CHAR cIn, CY *pcyOut);
WINOLEAUTAPI VarCyFromUI2(USHORT uiIn, CY *pcyOut);
WINOLEAUTAPI VarCyFromUI4(ULONG ulIn, CY *pcyOut);
WINOLEAUTAPI VarCyFromDec(DECIMAL *pdecIn, CY *pcyOut);

WINOLEAUTAPI VarBstrFromUI1(BYTE bVal, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
WINOLEAUTAPI VarBstrFromI2(SHORT iVal, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
WINOLEAUTAPI VarBstrFromI4(LONG lIn, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
WINOLEAUTAPI VarBstrFromR4(FLOAT fltIn, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
WINOLEAUTAPI VarBstrFromR8(DOUBLE dblIn, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
WINOLEAUTAPI VarBstrFromCy(CY cyIn, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
WINOLEAUTAPI VarBstrFromDate(DATE dateIn, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
WINOLEAUTAPI VarBstrFromDisp(IDispatch * pdispIn, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
WINOLEAUTAPI VarBstrFromBool(VARIANT_BOOL boolIn, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
WINOLEAUTAPI VarBstrFromI1(CHAR cIn, LCID lcid, ULONG dwFlags, BSTR *pbstrOut);
WINOLEAUTAPI VarBstrFromUI2(USHORT uiIn, LCID lcid, ULONG dwFlags, BSTR *pbstrOut);
WINOLEAUTAPI VarBstrFromUI4(ULONG ulIn, LCID lcid, ULONG dwFlags, BSTR *pbstrOut);
WINOLEAUTAPI VarBstrFromDec(DECIMAL *pdecIn, LCID lcid, ULONG dwFlags, BSTR *pbstrOut);

WINOLEAUTAPI VarBoolFromUI1(BYTE bIn, VARIANT_BOOL * pboolOut);
WINOLEAUTAPI VarBoolFromI2(SHORT sIn, VARIANT_BOOL * pboolOut);
WINOLEAUTAPI VarBoolFromI4(LONG lIn, VARIANT_BOOL * pboolOut);
WINOLEAUTAPI VarBoolFromR4(FLOAT fltIn, VARIANT_BOOL * pboolOut);
WINOLEAUTAPI VarBoolFromR8(DOUBLE dblIn, VARIANT_BOOL * pboolOut);
WINOLEAUTAPI VarBoolFromDate(DATE dateIn, VARIANT_BOOL * pboolOut);
WINOLEAUTAPI VarBoolFromCy(CY cyIn, VARIANT_BOOL * pboolOut);
WINOLEAUTAPI VarBoolFromStr(OLECHAR * strIn, LCID lcid, ULONG dwFlags, VARIANT_BOOL * pboolOut);
WINOLEAUTAPI VarBoolFromDisp(IDispatch * pdispIn, LCID lcid, VARIANT_BOOL * pboolOut);
WINOLEAUTAPI VarBoolFromI1(CHAR cIn, VARIANT_BOOL *pboolOut);
WINOLEAUTAPI VarBoolFromUI2(USHORT uiIn, VARIANT_BOOL *pboolOut);
WINOLEAUTAPI VarBoolFromUI4(ULONG ulIn, VARIANT_BOOL *pboolOut);
WINOLEAUTAPI VarBoolFromDec(DECIMAL *pdecIn, VARIANT_BOOL *pboolOut);

WINOLEAUTAPI VarI1FromUI1(BYTE bIn, CHAR *pcOut);
WINOLEAUTAPI VarI1FromI2(SHORT uiIn, CHAR *pcOut);
WINOLEAUTAPI VarI1FromI4(LONG lIn, CHAR *pcOut);
WINOLEAUTAPI VarI1FromR4(FLOAT fltIn, CHAR *pcOut);
WINOLEAUTAPI VarI1FromR8(DOUBLE dblIn, CHAR *pcOut);
WINOLEAUTAPI VarI1FromDate(DATE dateIn, CHAR *pcOut);
WINOLEAUTAPI VarI1FromCy(CY cyIn, CHAR *pcOut);
WINOLEAUTAPI VarI1FromStr(OLECHAR *strIn, LCID lcid, ULONG dwFlags, CHAR *pcOut);
WINOLEAUTAPI VarI1FromDisp(IDispatch *pdispIn, LCID lcid, CHAR *pcOut);
WINOLEAUTAPI VarI1FromBool(VARIANT_BOOL boolIn, CHAR *pcOut);
WINOLEAUTAPI VarI1FromUI2(USHORT uiIn, CHAR *pcOut);
WINOLEAUTAPI VarI1FromUI4(ULONG ulIn, CHAR *pcOut);
WINOLEAUTAPI VarI1FromDec(DECIMAL *pdecIn, CHAR *pcOut);

WINOLEAUTAPI VarUI2FromUI1(BYTE bIn, USHORT *puiOut);
WINOLEAUTAPI VarUI2FromI2(SHORT uiIn, USHORT *puiOut);
WINOLEAUTAPI VarUI2FromI4(LONG lIn, USHORT *puiOut);
WINOLEAUTAPI VarUI2FromR4(FLOAT fltIn, USHORT *puiOut);
WINOLEAUTAPI VarUI2FromR8(DOUBLE dblIn, USHORT *puiOut);
WINOLEAUTAPI VarUI2FromDate(DATE dateIn, USHORT *puiOut);
WINOLEAUTAPI VarUI2FromCy(CY cyIn, USHORT *puiOut);
WINOLEAUTAPI VarUI2FromStr(OLECHAR *strIn, LCID lcid, ULONG dwFlags, USHORT *puiOut);
WINOLEAUTAPI VarUI2FromDisp(IDispatch *pdispIn, LCID lcid, USHORT *puiOut);
WINOLEAUTAPI VarUI2FromBool(VARIANT_BOOL boolIn, USHORT *puiOut);
WINOLEAUTAPI VarUI2FromI1(CHAR cIn, USHORT *puiOut);
WINOLEAUTAPI VarUI2FromUI4(ULONG ulIn, USHORT *puiOut);
WINOLEAUTAPI VarUI2FromDec(DECIMAL *pdecIn, USHORT *puiOut);

WINOLEAUTAPI VarUI4FromUI1(BYTE bIn, ULONG *pulOut);
WINOLEAUTAPI VarUI4FromI2(SHORT uiIn, ULONG *pulOut);
WINOLEAUTAPI VarUI4FromI4(LONG lIn, ULONG *pulOut);
WINOLEAUTAPI VarUI4FromR4(FLOAT fltIn, ULONG *pulOut);
WINOLEAUTAPI VarUI4FromR8(DOUBLE dblIn, ULONG *pulOut);
WINOLEAUTAPI VarUI4FromDate(DATE dateIn, ULONG *pulOut);
WINOLEAUTAPI VarUI4FromCy(CY cyIn, ULONG *pulOut);
WINOLEAUTAPI VarUI4FromStr(OLECHAR *strIn, LCID lcid, ULONG dwFlags, ULONG *pulOut);
WINOLEAUTAPI VarUI4FromDisp(IDispatch *pdispIn, LCID lcid, ULONG *pulOut);
WINOLEAUTAPI VarUI4FromBool(VARIANT_BOOL boolIn, ULONG *pulOut);
WINOLEAUTAPI VarUI4FromI1(CHAR cIn, ULONG *pulOut);
WINOLEAUTAPI VarUI4FromUI2(USHORT uiIn, ULONG *pulOut);
WINOLEAUTAPI VarUI4FromDec(DECIMAL *pdecIn, ULONG *pulOut);

WINOLEAUTAPI VarDecFromUI1(BYTE bIn, DECIMAL *pdecOut);
WINOLEAUTAPI VarDecFromI2(SHORT uiIn, DECIMAL *pdecOut);
WINOLEAUTAPI VarDecFromI4(LONG lIn, DECIMAL *pdecOut);
WINOLEAUTAPI VarDecFromR4(FLOAT fltIn, DECIMAL *pdecOut);
WINOLEAUTAPI VarDecFromR8(DOUBLE dblIn, DECIMAL *pdecOut);
WINOLEAUTAPI VarDecFromDate(DATE dateIn, DECIMAL *pdecOut);
WINOLEAUTAPI VarDecFromCy(CY cyIn, DECIMAL *pdecOut);
WINOLEAUTAPI VarDecFromStr(OLECHAR *strIn, LCID lcid, ULONG dwFlags, DECIMAL *pdecOut);
WINOLEAUTAPI VarDecFromDisp(IDispatch *pdispIn, LCID lcid, DECIMAL *pdecOut);
WINOLEAUTAPI VarDecFromBool(VARIANT_BOOL boolIn, DECIMAL *pdecOut);
WINOLEAUTAPI VarDecFromI1(CHAR cIn, DECIMAL *pdecOut);
WINOLEAUTAPI VarDecFromUI2(USHORT uiIn, DECIMAL *pdecOut);
WINOLEAUTAPI VarDecFromUI4(ULONG ulIn, DECIMAL *pdecOut);

#define VarUI4FromUI4(in, pOut) (*(pOut) = (in))
#define VarI4FromI4(in, pOut)   (*(pOut) = (in))

#define VarUI1FromInt       VarUI1FromI4
#define VarUI1FromUint      VarUI1FromUI4
#define VarI2FromInt        VarI2FromI4
#define VarI2FromUint       VarI2FromUI4
#define VarI4FromInt        VarI4FromI4
#define VarI4FromUint       VarI4FromUI4
#define VarR4FromInt        VarR4FromI4
#define VarR4FromUint       VarR4FromUI4
#define VarR8FromInt        VarR8FromI4
#define VarR8FromUint       VarR8FromUI4
#define VarDateFromInt      VarDateFromI4
#define VarDateFromUint     VarDateFromUI4
#define VarCyFromInt        VarCyFromI4
#define VarCyFromUint       VarCyFromUI4
#define VarBstrFromInt      VarBstrFromI4
#define VarBstrFromUint     VarBstrFromUI4
#define VarBoolFromInt      VarBoolFromI4
#define VarBoolFromUint     VarBoolFromUI4
#define VarI1FromInt        VarI1FromI4
#define VarI1FromUint       VarI1FromUI4
#define VarUI2FromInt       VarUI2FromI4
#define VarUI2FromUint      VarUI2FromUI4
#define VarUI4FromInt       VarUI4FromI4
#define VarUI4FromUint      VarUI4FromUI4
#define VarDecFromInt       VarDecFromI4
#define VarDecFromUint      VarDecFromUI4
#define VarIntFromUI1       VarI4FromUI1
#define VarIntFromI2        VarI4FromI2
#define VarIntFromI4        VarI4FromI4
#define VarIntFromR4        VarI4FromR4
#define VarIntFromR8        VarI4FromR8
#define VarIntFromDate      VarI4FromDate
#define VarIntFromCy        VarI4FromCy
#define VarIntFromStr       VarI4FromStr
#define VarIntFromDisp      VarI4FromDisp
#define VarIntFromBool      VarI4FromBool
#define VarIntFromI1        VarI4FromI1
#define VarIntFromUI2       VarI4FromUI2
#define VarIntFromUI4       VarI4FromUI4
#define VarIntFromDec       VarI4FromDec
#define VarIntFromUint      VarI4FromUI4
#define VarUintFromUI1      VarUI4FromUI1
#define VarUintFromI2       VarUI4FromI2
#define VarUintFromI4       VarUI4FromI4
#define VarUintFromR4       VarUI4FromR4
#define VarUintFromR8       VarUI4FromR8
#define VarUintFromDate     VarUI4FromDate
#define VarUintFromCy       VarUI4FromCy
#define VarUintFromStr      VarUI4FromStr
#define VarUintFromDisp     VarUI4FromDisp
#define VarUintFromBool     VarUI4FromBool
#define VarUintFromI1       VarUI4FromI1
#define VarUintFromUI2      VarUI4FromUI2
#define VarUintFromUI4      VarUI4FromUI4
#define VarUintFromDec      VarUI4FromDec
#define VarUintFromInt      VarUI4FromI4

/* Mac Note: On the Mac, the coersion functions support the
 * Symantec C++ calling convention for float/double. To support
 * float/double arguments compiled with the MPW C compiler,
 * use the following APIs to move MPW float/double values into
 * a VARIANT.
 */

/*---------------------------------------------------------------------*/
/*            New VARIANT <-> string parsing functions                 */
/*---------------------------------------------------------------------*/

typedef struct {
    INT   cDig;
    ULONG dwInFlags;
    ULONG dwOutFlags;
    INT   cchUsed;
    INT   nBaseShift;
    INT   nPwr10;
} NUMPARSE;

/* flags used by both dwInFlags and dwOutFlags:
 */
#define NUMPRS_LEADING_WHITE    0x0001
#define NUMPRS_TRAILING_WHITE   0x0002
#define NUMPRS_LEADING_PLUS     0x0004
#define NUMPRS_TRAILING_PLUS    0x0008
#define NUMPRS_LEADING_MINUS    0x0010
#define NUMPRS_TRAILING_MINUS   0x0020
#define NUMPRS_HEX_OCT          0x0040
#define NUMPRS_PARENS           0x0080
#define NUMPRS_DECIMAL          0x0100
#define NUMPRS_THOUSANDS        0x0200
#define NUMPRS_CURRENCY         0x0400
#define NUMPRS_EXPONENT         0x0800
#define NUMPRS_USE_ALL          0x1000
#define NUMPRS_STD              0x1FFF

/* flags used by dwOutFlags only:
 */
#define NUMPRS_NEG              0x10000
#define NUMPRS_INEXACT          0x20000

/* flags used by VarNumFromParseNum to indicate acceptable result types:
 */
#define VTBIT_I1        (1 << VT_I1)
#define VTBIT_UI1       (1 << VT_UI1)
#define VTBIT_I2        (1 << VT_I2)
#define VTBIT_UI2       (1 << VT_UI2)
#define VTBIT_I4        (1 << VT_I4)
#define VTBIT_UI4       (1 << VT_UI4)
#define VTBIT_R4        (1 << VT_R4)
#define VTBIT_R8        (1 << VT_R8)
#define VTBIT_CY        (1 << VT_CY)
#define VTBIT_DECIMAL   (1 << VT_DECIMAL)


WINOLEAUTAPI VarParseNumFromStr(OLECHAR * strIn, LCID lcid, ULONG dwFlags,
            NUMPARSE * pnumprs, BYTE * rgbDig);

WINOLEAUTAPI VarNumFromParseNum(NUMPARSE * pnumprs, BYTE * rgbDig,
            ULONG dwVtBits, VARIANT * pvar);

/*---------------------------------------------------------------------*/
/*                     VARTYPE Math API                                */
/*---------------------------------------------------------------------*/

STDAPI VarAdd(LPVARIANT pvarLeft, LPVARIANT pvarRight, LPVARIANT pvarResult);
STDAPI VarAnd(LPVARIANT pvarLeft, LPVARIANT pvarRight, LPVARIANT pvarResult);
STDAPI VarCat(LPVARIANT pvarLeft, LPVARIANT pvarRight, LPVARIANT pvarResult);
STDAPI VarDiv(LPVARIANT pvarLeft, LPVARIANT pvarRight, LPVARIANT pvarResult);
STDAPI VarEqv(LPVARIANT pvarLeft, LPVARIANT pvarRight, LPVARIANT pvarResult);
STDAPI VarIdiv(LPVARIANT pvarLeft, LPVARIANT pvarRight, LPVARIANT pvarResult);
STDAPI VarImp(LPVARIANT pvarLeft, LPVARIANT pvarRight, LPVARIANT pvarResult);
STDAPI VarMod(LPVARIANT pvarLeft, LPVARIANT pvarRight, LPVARIANT pvarResult);
STDAPI VarMul(LPVARIANT pvarLeft, LPVARIANT pvarRight, LPVARIANT pvarResult);
STDAPI VarOr(LPVARIANT pvarLeft, LPVARIANT pvarRight, LPVARIANT pvarResult);
STDAPI VarPow(LPVARIANT pvarLeft, LPVARIANT pvarRight, LPVARIANT pvarResult);
STDAPI VarSub(LPVARIANT pvarLeft, LPVARIANT pvarRight, LPVARIANT pvarResult);
STDAPI VarXor(LPVARIANT pvarLeft, LPVARIANT pvarRight, LPVARIANT pvarResult);

STDAPI VarAbs(LPVARIANT pvarIn, LPVARIANT pvarResult);
STDAPI VarFix(LPVARIANT pvarIn, LPVARIANT pvarResult);
STDAPI VarInt(LPVARIANT pvarIn, LPVARIANT pvarResult);
STDAPI VarNeg(LPVARIANT pvarIn, LPVARIANT pvarResult);
STDAPI VarNot(LPVARIANT pvarIn, LPVARIANT pvarResult);

STDAPI VarRound(LPVARIANT pvarIn, int cDecimals, LPVARIANT pvarResult);

// dwFlags passed to CompareString if a string compare
STDAPI VarCmp(LPVARIANT pvarLeft, LPVARIANT pvarRight, LCID lcid, ULONG dwFlags);


// Decimal math
//
STDAPI VarDecAdd(LPDECIMAL pdecLeft, LPDECIMAL pdecRight, LPDECIMAL pdecResult);
STDAPI VarDecDiv(LPDECIMAL pdecLeft, LPDECIMAL pdecRight, LPDECIMAL pdecResult);
STDAPI VarDecMul(LPDECIMAL pdecLeft, LPDECIMAL pdecRight, LPDECIMAL pdecResult);
STDAPI VarDecSub(LPDECIMAL pdecLeft, LPDECIMAL pdecRight, LPDECIMAL pdecResult);

STDAPI VarDecAbs(LPDECIMAL pdecIn, LPDECIMAL pdecResult);
STDAPI VarDecFix(LPDECIMAL pdecIn, LPDECIMAL pdecResult);
STDAPI VarDecInt(LPDECIMAL pdecIn, LPDECIMAL pdecResult);
STDAPI VarDecNeg(LPDECIMAL pdecIn, LPDECIMAL pdecResult);

STDAPI VarDecRound(LPDECIMAL pdecIn, int cDecimals, LPDECIMAL pdecResult);

STDAPI VarDecCmp(LPDECIMAL pdecLeft, LPDECIMAL pdecRight);
STDAPI VarDecCmpR8(LPDECIMAL pdecLeft, double dblRight);


// Currency math
//
STDAPI VarCyAdd(CY cyLeft, CY cyRight, LPCY pcyResult);
STDAPI VarCyMul(CY cyLeft, CY cyRight, LPCY pcyResult);
STDAPI VarCyMulI4(CY cyLeft, long lRight, LPCY pcyResult);
STDAPI VarCySub(CY cyLeft, CY cyRight, LPCY pcyResult);

STDAPI VarCyAbs(CY cyIn, LPCY pcyResult);
STDAPI VarCyFix(CY cyIn, LPCY pcyResult);
STDAPI VarCyInt(CY cyIn, LPCY pcyResult);
STDAPI VarCyNeg(CY cyIn, LPCY pcyResult);

STDAPI VarCyRound(CY cyIn, int cDecimals, LPCY pcyResult);

STDAPI VarCyCmp(CY cyLeft, CY cyRight);
STDAPI VarCyCmpR8(CY cyLeft, double dblRight);


// Misc support functions
//
STDAPI VarBstrCat(BSTR bstrLeft, BSTR bstrRight, LPBSTR pbstrResult);
STDAPI VarBstrCmp(BSTR bstrLeft, BSTR bstrRight, LCID lcid, ULONG dwFlags); // dwFlags passed to CompareString
STDAPI VarR8Pow(double dblLeft, double dblRight, double *pdblResult);
STDAPI VarR4CmpR8(float fltLeft, double dblRight);
STDAPI VarR8Round(double dblIn, int cDecimals, double *pdblResult);


// Compare results.  These are returned as a SUCCESS HResult.  Subtracting
// one gives the usual values of -1 for Less Than, 0 for Equal To, +1 for
// Greater Than.
//
#define VARCMP_LT   0
#define VARCMP_EQ   1
#define VARCMP_GT   2
#define VARCMP_NULL 3

// VT_HARDTYPE tells the compare routine that the argument is a literal or
// otherwise declared of that specific type.  It causes comparison rules to 
// change. For example, if a hard-type string is compared to a variant (not hard
// -type) number, the number is converted to string.  If a hard-type number is 
// compared to a variant string, the string is converted to number.  If they're 
// both variant, then number < string.
#define VT_HARDTYPE VT_RESERVED

/*---------------------------------------------------------------------*/
/*                   New date functions                                */
/*---------------------------------------------------------------------*/

/* The UDATE structure is used with VarDateFromUdate() and VarUdateFromDate().
 * It represents an "unpacked date".
 */
typedef struct {
    SYSTEMTIME st;
    USHORT  wDayOfYear;
} UDATE;

/* APIs to "pack" and "unpack" dates.
 * NOTE: Ex version of VarDateFromUdate obeys 2 digit year setting in
 * control panel.
 */
WINOLEAUTAPI VarDateFromUdate(UDATE *pudateIn, ULONG dwFlags, DATE *pdateOut);
WINOLEAUTAPI VarDateFromUdateEx(UDATE *pudateIn, LCID lcid, ULONG dwFlags, DATE *pdateOut);
WINOLEAUTAPI VarUdateFromDate(DATE dateIn, ULONG dwFlags, UDATE *pudateOut);

/* API to retrieve the secondary(altername) month names
   Useful for Hijri, Polish and Russian alternate month names
*/   
WINOLEAUTAPI GetAltMonthNames(LCID lcid, LPOLESTR * * prgp);

/*---------------------------------------------------------------------*/
/*                 Format                                              */
/*---------------------------------------------------------------------*/

WINOLEAUTAPI VarFormat(LPVARIANT pvarIn, LPOLESTR pstrFormat, int iFirstDay, int iFirstWeek, ULONG dwFlags, BSTR *pbstrOut);
WINOLEAUTAPI VarFormatDateTime(LPVARIANT pvarIn, int iNamedFormat, ULONG dwFlags, BSTR *pbstrOut);
WINOLEAUTAPI VarFormatNumber(LPVARIANT pvarIn, int iNumDig, int iIncLead, int iUseParens, int iGroup, ULONG dwFlags, BSTR *pbstrOut);
WINOLEAUTAPI VarFormatPercent(LPVARIANT pvarIn, int iNumDig, int iIncLead, int iUseParens, int iGroup, ULONG dwFlags, BSTR *pbstrOut);
WINOLEAUTAPI VarFormatCurrency(LPVARIANT pvarIn, int iNumDig, int iIncLead, int iUseParens, int iGroup, ULONG dwFlags, BSTR *pbstrOut);

WINOLEAUTAPI VarWeekdayName(int iWeekday, int fAbbrev, int iFirstDay, ULONG dwFlags, BSTR *pbstrOut);
WINOLEAUTAPI VarMonthName(int iMonth, int fAbbrev, ULONG dwFlags, BSTR *pbstrOut);

WINOLEAUTAPI VarFormatFromTokens(LPVARIANT pvarIn, LPOLESTR pstrFormat, LPBYTE pbTokCur, ULONG dwFlags, BSTR *pbstrOut, LCID lcid);
WINOLEAUTAPI VarTokenizeFormatString(LPOLESTR pstrFormat, LPBYTE rgbTok, int cbTok, int iFirstDay, int iFirstWeek, LCID lcid, int *pcbActual);

/*---------------------------------------------------------------------*/
/*                 ITypeLib                                            */
/*---------------------------------------------------------------------*/

typedef ITypeLib * LPTYPELIB;


/*---------------------------------------------------------------------*/
/*                ITypeInfo                                            */
/*---------------------------------------------------------------------*/


typedef LONG DISPID;
typedef DISPID MEMBERID;

#define MEMBERID_NIL DISPID_UNKNOWN
#define ID_DEFAULTINST  -2


/* Flags for IDispatch::Invoke */
#define DISPATCH_METHOD         0x1
#define DISPATCH_PROPERTYGET    0x2
#define DISPATCH_PROPERTYPUT    0x4
#define DISPATCH_PROPERTYPUTREF 0x8

typedef ITypeInfo * LPTYPEINFO;


/*---------------------------------------------------------------------*/
/*                ITypeComp                                            */
/*---------------------------------------------------------------------*/

typedef ITypeComp * LPTYPECOMP;


/*---------------------------------------------------------------------*/
/*             ICreateTypeLib                                          */
/*---------------------------------------------------------------------*/

typedef ICreateTypeLib * LPCREATETYPELIB;

typedef ICreateTypeInfo * LPCREATETYPEINFO;

/*---------------------------------------------------------------------*/
/*             TypeInfo API                                            */
/*---------------------------------------------------------------------*/

/* compute a 16bit hash value for the given name
 */
#ifdef _WIN32
WINOLEAUTAPI_(ULONG) LHashValOfNameSysA(SYSKIND syskind, LCID lcid,
            LPCSTR szName);
#endif

WINOLEAUTAPI_(ULONG)
LHashValOfNameSys(SYSKIND syskind, LCID lcid, const OLECHAR * szName);

#define LHashValOfName(lcid, szName) \
            LHashValOfNameSys(SYS_WIN32, lcid, szName)

#define WHashValOfLHashVal(lhashval) \
            ((USHORT) (0x0000ffff & (lhashval)))

#define IsHashValCompatible(lhashval1, lhashval2) \
            ((BOOL) ((0x00ff0000 & (lhashval1)) == (0x00ff0000 & (lhashval2))))

/* load the typelib from the file with the given filename
 */
WINOLEAUTAPI LoadTypeLib(const OLECHAR  *szFile, ITypeLib ** pptlib);

/* Control how a type library is registered
 */
typedef enum tagREGKIND
{
    REGKIND_DEFAULT,
    REGKIND_REGISTER,
    REGKIND_NONE
} REGKIND;

WINOLEAUTAPI LoadTypeLibEx(LPCOLESTR szFile, REGKIND regkind,
            ITypeLib ** pptlib);

/* load registered typelib
 */
WINOLEAUTAPI LoadRegTypeLib(REFGUID rguid, WORD wVerMajor, WORD wVerMinor,
            LCID lcid, ITypeLib ** pptlib);

/* get path to registered typelib
 */
WINOLEAUTAPI QueryPathOfRegTypeLib(REFGUID guid, USHORT wMaj, USHORT wMin,
            LCID lcid, LPBSTR lpbstrPathName);

/* add typelib to registry
 */
WINOLEAUTAPI RegisterTypeLib(ITypeLib * ptlib, OLECHAR  *szFullPath,
            OLECHAR  *szHelpDir);

/* remove typelib from registry
 */

WINOLEAUTAPI UnRegisterTypeLib(REFGUID libID, WORD wVerMajor,
            WORD wVerMinor, LCID lcid, SYSKIND syskind);

WINOLEAUTAPI CreateTypeLib(SYSKIND syskind, const OLECHAR  *szFile,
            ICreateTypeLib ** ppctlib);

WINOLEAUTAPI CreateTypeLib2(SYSKIND syskind, LPCOLESTR szFile,
            ICreateTypeLib2 **ppctlib);


/*---------------------------------------------------------------------*/
/*           IDispatch implementation support                          */
/*---------------------------------------------------------------------*/

typedef IDispatch * LPDISPATCH;

typedef struct tagPARAMDATA {
    OLECHAR * szName;   /* parameter name */
    VARTYPE vt;         /* parameter type */
} PARAMDATA, * LPPARAMDATA;

typedef struct tagMETHODDATA {
    OLECHAR * szName;   /* method name */
    PARAMDATA * ppdata; /* pointer to an array of PARAMDATAs */
    DISPID dispid;      /* method ID */
    UINT iMeth;         /* method index */
    CALLCONV cc;        /* calling convention */
    UINT cArgs;         /* count of arguments */
    WORD wFlags;        /* same wFlags as on IDispatch::Invoke() */
    VARTYPE vtReturn;
} METHODDATA, * LPMETHODDATA;

typedef struct tagINTERFACEDATA {
    METHODDATA * pmethdata;  /* pointer to an array of METHODDATAs */
    UINT cMembers;      /* count of members */
} INTERFACEDATA, * LPINTERFACEDATA;



/* Locate the parameter indicated by the given position, and
 * return it coerced to the given target VARTYPE (vtTarg).
 */
WINOLEAUTAPI DispGetParam(DISPPARAMS * pdispparams, UINT position,
            VARTYPE vtTarg, VARIANT * pvarResult, UINT * puArgErr);

/* Automatic TypeInfo driven implementation of IDispatch::GetIDsOfNames()
 */
WINOLEAUTAPI DispGetIDsOfNames(ITypeInfo * ptinfo, OLECHAR ** rgszNames,
            UINT cNames, DISPID * rgdispid);

/* Automatic TypeInfo driven implementation of IDispatch::Invoke()
 */
WINOLEAUTAPI DispInvoke(void * _this, ITypeInfo * ptinfo, DISPID dispidMember,
            WORD wFlags, DISPPARAMS * pparams, VARIANT * pvarResult,
            EXCEPINFO * pexcepinfo, UINT * puArgErr);

/* Construct a TypeInfo from an interface data description
 */
WINOLEAUTAPI CreateDispTypeInfo(INTERFACEDATA * pidata, LCID lcid,
            ITypeInfo ** pptinfo);

/* Create an instance of the standard TypeInfo driven IDispatch
 * implementation.
 */
WINOLEAUTAPI CreateStdDispatch(IUnknown * punkOuter, void * pvThis,
            ITypeInfo * ptinfo, IUnknown ** ppunkStdDisp);

/* Low-level helper for IDispatch::Invoke() provides machine independence
 * for customized Invoke().
 */
WINOLEAUTAPI DispCallFunc(void * pvInstance, ULONG oVft, CALLCONV cc,
            VARTYPE vtReturn, UINT  cActuals, VARTYPE * prgvt,
            VARIANTARG ** prgpvarg, VARIANT * pvargResult);


/*---------------------------------------------------------------------*/
/*            Active Object Registration API                           */
/*---------------------------------------------------------------------*/

/* flags for RegisterActiveObject */
#define ACTIVEOBJECT_STRONG 0x0
#define ACTIVEOBJECT_WEAK 0x1

WINOLEAUTAPI RegisterActiveObject(IUnknown * punk, REFCLSID rclsid,
            DWORD dwFlags, DWORD * pdwRegister);

WINOLEAUTAPI RevokeActiveObject(DWORD dwRegister, void * pvReserved);

WINOLEAUTAPI GetActiveObject(REFCLSID rclsid, void * pvReserved,
            IUnknown ** ppunk);

/*---------------------------------------------------------------------*/
/*                           ErrorInfo API                             */
/*---------------------------------------------------------------------*/

WINOLEAUTAPI SetErrorInfo(ULONG dwReserved, IErrorInfo * perrinfo);
WINOLEAUTAPI GetErrorInfo(ULONG dwReserved, IErrorInfo ** pperrinfo);
WINOLEAUTAPI CreateErrorInfo(ICreateErrorInfo ** pperrinfo);

/*---------------------------------------------------------------------*/
/*           User Defined Data types support                           */
/*---------------------------------------------------------------------*/

WINOLEAUTAPI GetRecordInfoFromTypeInfo(ITypeInfo * pTypeInfo,
            IRecordInfo ** ppRecInfo);

WINOLEAUTAPI GetRecordInfoFromGuids(REFGUID rGuidTypeLib,
            ULONG uVerMajor, ULONG uVerMinor, LCID lcid,
            REFGUID rGuidTypeInfo, IRecordInfo ** ppRecInfo);

/*---------------------------------------------------------------------*/
/*                           MISC API                                  */
/*---------------------------------------------------------------------*/

WINOLEAUTAPI_(ULONG) OaBuildVersion(void);

WINOLEAUTAPI_(void) ClearCustData(LPCUSTDATA pCustData);

// Declare variant access functions.

#if __STDC__ || defined(NONAMELESSUNION)
#define V_UNION(X, Y)   ((X)->n1.n2.n3.Y)
#define V_VT(X)         ((X)->n1.n2.vt)
#define V_RECORDINFO(X) ((X)->n1.n2.n3.brecVal.pRecInfo)
#define V_RECORD(X)     ((X)->n1.n2.n3.brecVal.pvRecord)
#else
#define V_UNION(X, Y)   ((X)->Y)
#define V_VT(X)         ((X)->vt)
#define V_RECORDINFO(X) ((X)->pRecInfo)
#define V_RECORD(X)     ((X)->pvRecord)
#endif

/* Variant access macros
 */
#define V_ISBYREF(X)     (V_VT(X)&VT_BYREF)
#define V_ISARRAY(X)     (V_VT(X)&VT_ARRAY)
#define V_ISVECTOR(X)    (V_VT(X)&VT_VECTOR)
#define V_NONE(X)        V_I2(X)

#define V_UI1(X)         V_UNION(X, bVal)
#define V_UI1REF(X)      V_UNION(X, pbVal)
#define V_I2(X)          V_UNION(X, iVal)
#define V_I2REF(X)       V_UNION(X, piVal)
#define V_I4(X)          V_UNION(X, lVal)
#define V_I4REF(X)       V_UNION(X, plVal)
#define V_R4(X)          V_UNION(X, fltVal)
#define V_R4REF(X)       V_UNION(X, pfltVal)
#define V_R8(X)          V_UNION(X, dblVal)
#define V_R8REF(X)       V_UNION(X, pdblVal)
#define V_I1(X)          V_UNION(X, cVal)
#define V_I1REF(X)       V_UNION(X, pcVal)
#define V_UI2(X)         V_UNION(X, uiVal)
#define V_UI2REF(X)      V_UNION(X, puiVal)
#define V_UI4(X)         V_UNION(X, ulVal)
#define V_UI4REF(X)      V_UNION(X, pulVal)
#define V_INT(X)         V_UNION(X, intVal)
#define V_INTREF(X)      V_UNION(X, pintVal)
#define V_UINT(X)        V_UNION(X, uintVal)
#define V_UINTREF(X)     V_UNION(X, puintVal)
#define V_CY(X)          V_UNION(X, cyVal)
#define V_CYREF(X)       V_UNION(X, pcyVal)
#define V_DATE(X)        V_UNION(X, date)
#define V_DATEREF(X)     V_UNION(X, pdate)
#define V_BSTR(X)        V_UNION(X, bstrVal)
#define V_BSTRREF(X)     V_UNION(X, pbstrVal)
#define V_DISPATCH(X)    V_UNION(X, pdispVal)
#define V_DISPATCHREF(X) V_UNION(X, ppdispVal)
#define V_ERROR(X)       V_UNION(X, scode)
#define V_ERRORREF(X)    V_UNION(X, pscode)
#define V_BOOL(X)        V_UNION(X, boolVal)
#define V_BOOLREF(X)     V_UNION(X, pboolVal)
#define V_UNKNOWN(X)     V_UNION(X, punkVal)
#define V_UNKNOWNREF(X)  V_UNION(X, ppunkVal)
#define V_VARIANTREF(X)  V_UNION(X, pvarVal)
#define V_ARRAY(X)       V_UNION(X, parray)
#define V_ARRAYREF(X)    V_UNION(X, pparray)
#define V_BYREF(X)       V_UNION(X, byref)

#define V_DECIMAL(X)     V_UNION(X, decVal)
#define V_DECIMALREF(X)  V_UNION(X, pdecVal)

#ifndef RC_INVOKED
#include <poppack.h>
#endif // RC_INVOKED

#endif     // __OLEAUTO_H__
