/*******************************************************************************
*
*  (C) COPYRIGHT AUTHORS, 2015 - 2018
*
*  TITLE:       HYBRIDS.H
*
*  VERSION:     3.00
*
*  DATE:        25 Aug 2018
*
*  Prototypes and definitions for hybrid methods.
*
* THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
* ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
* TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
* PARTICULAR PURPOSE.
*
*******************************************************************************/
#pragma once

typedef BOOL(WINAPI *pfnShellExecuteExW)(
    SHELLEXECUTEINFOW *pExecInfo);

typedef DWORD(WINAPI *pfnWaitForSingleObject)(
    HANDLE hHandle,
    DWORD dwMilliseconds);

typedef BOOL(WINAPI *pfnCloseHandle)(
    HANDLE hObject);

typedef HRESULT(WINAPI *pfnCoInitialize)(
    LPVOID pvReserved);

typedef HRESULT(WINAPI *pfnCoGetObject)(
    LPCWSTR pszName,
    BIND_OPTS *pBindOptions,
    REFIID riid,
    void **ppv);

typedef HRESULT(WINAPI *pfnSHCreateItemFromParsingName)(
    PCWSTR pszPath, 
    IBindCtx *pbc, 
    REFIID riid, 
    void **ppv);

typedef void(WINAPI *pfnCoUninitialize)(
    VOID);

typedef NTSTATUS (NTAPI *pfnRtlExitUserThread)(
    _In_ NTSTATUS ExitStatus);

typedef struct tagLOAD_PARAMETERS_SIREFEF {
    WCHAR                   szVerb[10];
    WCHAR                   szTargetApp[MAX_PATH + 1];
    pfnShellExecuteExW      ShellExecuteExW;
    pfnWaitForSingleObject  WaitForSingleObject;
    pfnCloseHandle          CloseHandle;
    pfnRtlExitUserThread    RtlExitUserThread;
} LOAD_PARAMETERS_SIREFEF, *PLOAD_PARAMETERS_SIREFEF;

BOOL ucmAvrfMethod(
    _In_ PVOID AvrfDll,
    _In_ DWORD AvrfDllSize);

BOOL ucmWinSATMethod(
    _In_ LPWSTR lpTargetDll,
    _In_ PVOID ProxyDll,
    _In_ DWORD ProxyDllSize,
    _In_ BOOL UseWusa);

BOOL ucmMMCMethod(
    _In_ UCM_METHOD Method,
    _In_ LPWSTR lpTargetDll,
    _In_ PVOID ProxyDll,
    _In_ DWORD ProxyDllSize);

BOOL ucmSirefefMethod(
    _In_ PVOID ProxyDll,
    _In_ DWORD ProxyDllSize);

BOOL ucmGenericAutoelevation(
    _In_ LPWSTR lpTargetApp,
    _In_ LPWSTR lpTargetDll,
    _In_ PVOID ProxyDll,
    _In_ DWORD ProxyDllSize);

BOOL ucmGWX(
    _In_ PVOID ProxyDll,
    _In_ DWORD ProxyDllSize);

BOOL ucmAutoElevateManifest(
    _In_ PVOID ProxyDll,
    _In_ DWORD ProxyDllSize);

BOOL ucmInetMgrMethod(
    _In_ PVOID ProxyDll,
    _In_ DWORD ProxyDllSize);

BOOL ucmSXSMethod(
    _In_ PVOID ProxyDll,
    _In_ DWORD ProxyDllSize,
    _In_opt_ LPWSTR lpTargetDirectory,
    _In_ LPWSTR lpTargetApplication,
    _In_opt_ LPWSTR lpLaunchApplication,
    _In_ BOOL bConsentItself);

BOOL ucmSetupAkagiLink(
    VOID);

BOOL ucmDismMethod(
    _In_ PVOID ProxyDll,
    _In_ DWORD ProxyDllSize);

BOOL ucmWow64LoggerMethod(
    _In_ PVOID ProxyDll,
    _In_ DWORD ProxyDllSize);

BOOL ucmUiAccessMethod(
    _In_ PVOID ProxyDll,
    _In_ DWORD ProxyDllSize);

BOOL ucmJunctionMethod(
    _In_ PVOID ProxyDll,
    _In_ DWORD ProxyDllSize);

BOOL ucmSXSDccwMethod(
    _In_ PVOID ProxyDll,
    _In_ DWORD ProxyDllSize);

BOOL ucmCorProfilerMethod(
    _In_ PVOID ProxyDll,
    _In_ DWORD ProxyDllSize);

BOOL ucmFwCplLuaMethod(
    _In_ LPWSTR lpszPayload);

BOOL ucmDccwCOMMethod(
    _In_ LPWSTR lpszPayload);

BOOL ucmBitlockerRCMethod(
    _In_ LPWSTR lpszPayload);

BOOL ucmCOMHandlersMethod2(
    _In_ PVOID ProxyDll,
    _In_ DWORD ProxyDllSize);

BOOL ucmDateTimeStateWriterMethod(
    _In_ PVOID ProxyDll,
    _In_ DWORD ProxyDllSize);

BOOL ucmAcCplAdminMethod(
    _In_ LPWSTR lpszPayload);
