#ifndef _WSAHELP_H
#define _WSAHELP_H

#include <winsock2.h>
#include <ntsecapi.h>
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define WSH_NOTIFY_BIND 0x00000001
#define WSH_NOTIFY_LISTEN 0x00000002
#define WSH_NOTIFY_CONNECT 0x00000004
#define WSH_NOTIFY_ACCEPT 0x00000008
#define WSH_NOTIFY_SHUTDOWN_RECEIVE 0x00000010
#define WSH_NOTIFY_SHUTDOWN_SEND 0x00000020
#define WSH_NOTIFY_SHUTDOWN_ALL 0x00000040
#define WSH_NOTIFY_CLOSE 0x00000080
#define WSH_NOTIFY_CONNECT_ERROR 0x00000100
#define SOL_INTERNAL 0xFFFE
#define SO_CONTEXT 1

#ifndef RC_INVOKED
typedef enum _SOCKADDR_ADDRESS_INFO {
  SockaddrAddressInfoNormal,
  SockaddrAddressInfoWildcard,
  SockaddrAddressInfoBroadcast,
  SockaddrAddressInfoLoopback
} SOCKADDR_ADDRESS_INFO, *PSOCKADDR_ADDRESS_INFO;
typedef enum _SOCKADDR_ENDPOINT_INFO {
  SockaddrEndpointInfoNormal,
  SockaddrEndpointInfoWildcard,
  SockaddrEndpointInfoReserved
} SOCKADDR_ENDPOINT_INFO, *PSOCKADDR_ENDPOINT_INFO;
typedef struct _SOCKADDR_INFO {
  SOCKADDR_ADDRESS_INFO AddressInfo;
  SOCKADDR_ENDPOINT_INFO EndpointInfo;
} SOCKADDR_INFO, *PSOCKADDR_INFO;

INT WINAPI WSHAddressToString(LPSOCKADDR,INT,LPWSAPROTOCOL_INFOW,LPWSTR,LPDWORD);
INT WINAPI WSHEnumProtocols(LPINT,LPWSTR,LPVOID,LPDWORD);
INT WINAPI WSHGetBroadcastSockaddr(PVOID,PSOCKADDR,PINT);
INT WINAPI WSHGetProviderGuid(LPWSTR,LPGUID);
INT WINAPI WSHGetSockaddrType(PSOCKADDR,DWORD,PSOCKADDR_INFO);
INT WINAPI WSHGetSocketInformation(PVOID,SOCKET,HANDLE,HANDLE,INT,INT,PCHAR,INT);
INT WINAPI WSHGetWildcardSockaddr(PVOID,PSOCKADDR,PINT);
INT WINAPI WSHGetWSAProtocolInfo(LPWSTR,LPWSAPROTOCOL_INFOW*,LPDWORD);
INT WINAPI WSHIoctl(PVOID,SOCKET,HANDLE,HANDLE,DWORD,LPVOID,DWORD,LPVOID,DWORD,
LPDWORD,LPWSAOVERLAPPED,LPWSAOVERLAPPED_COMPLETION_ROUTINE,LPBOOL);
INT WINAPI WSHJoinLeaf(PVOID,SOCKET,HANDLE,HANDLE,PVOID,SOCKET,PSOCKADDR,
DWORD,LPWSABUF,LPWSABUF,LPQOS,LPQOS,DWORD);
INT WINAPI WSHNotify(PVOID,SOCKET,HANDLE,HANDLE,DWORD);
INT WINAPI WSHOpenSocket(PINT,PINT,PINT,PUNICODE_STRING,PVOID,PDWORD);
INT WINAPI WSHOpenSocket2(PINT,PINT,PINT,GROUP,DWORD,PUNICODE_STRING,PVOID*,PDWORD);
INT WINAPI WSHSetSocketInformation(PVOID,SOCKET,HANDLE,HANDLE,INT,INT,PCHAR,INT);
INT WINAPI WSHStringToAddress(LPWSTR,DWORD,LPWSAPROTOCOL_INFOW,LPSOCKADDR,LPDWORD);

typedef INT (WINAPI *PWSH_ADDRESS_TO_STRING)(LPSOCKADDR,INT,LPWSAPROTOCOL_INFOW,LPWSTR,LPDWORD);
typedef INT (WINAPI *PWSH_ENUM_PROTOCOLS)(LPINT,LPWSTR,LPVOID,LPDWORD);
typedef INT (WINAPI *PWSH_GET_BROADCAST_SOCKADDR)(PVOID,PSOCKADDR,PINT);
typedef INT (WINAPI *PWSH_GET_PROVIDER_GUID)(LPWSTR,LPGUID);
typedef INT (WINAPI *PWSH_GET_SOCKADDR_TYPE)(PSOCKADDR,DWORD,PSOCKADDR_INFO);
typedef INT (WINAPI *PWSH_GET_SOCKET_INFORMATION)(PVOID,SOCKET,HANDLE,HANDLE,INT,INT,PCHAR,INT);
typedef INT (WINAPI *PWSH_GET_WILDCARD_SOCKEADDR)(PVOID,PSOCKADDR,PINT);
typedef INT (WINAPI *PWSH_GET_WSAPROTOCOL_INFO)(LPWSTR,LPWSAPROTOCOL_INFOW*,LPDWORD);
typedef INT (WINAPI *PWSH_IOCTL)(PVOID,SOCKET,HANDLE,HANDLE,DWORD,LPVOID,DWORD,
	     LPVOID,DWORD,LPDWORD,LPWSAOVERLAPPED,LPWSAOVERLAPPED_COMPLETION_ROUTINE,LPBOOL);
typedef INT (WINAPI *PWSH_JOIN_LEAF)(PVOID,SOCKET,HANDLE,HANDLE,PVOID,SOCKET,
	     PSOCKADDR,DWORD,LPWSABUF,LPWSABUF,LPQOS,LPQOS,DWORD);
typedef INT (WINAPI *PWSH_NOTIFY)(PVOID,SOCKET,HANDLE,HANDLE,DWORD);
typedef INT (WINAPI *PWSH_OPEN_SOCKET)(PINT,PINT,PINT,PUNICODE_STRING,PVOID,PDWORD);
typedef INT (WINAPI *PWSH_OPEN_SOCKET2)(PINT,PINT,PINT,GROUP,DWORD,PUNICODE_STRING,PVOID*,PDWORD);
typedef INT (WINAPI *PWSH_SET_SOCKET_INFORMATION)(PVOID,SOCKET,HANDLE,HANDLE,INT,INT,PCHAR,INT);
typedef INT (WINAPI *PWSH_STRING_TO_ADDRESS)(LPWSTR,DWORD,LPWSAPROTOCOL_INFOW,LPSOCKADDR,LPDWORD);

#ifndef __OBJC__
/* "Protocol" is a builtin class name in ObjC.  */
typedef struct _WINSOCK_MAPPING {
	DWORD Rows;
	DWORD Columns;
	struct {
		DWORD AddressFamily;
		DWORD SocketType;
		DWORD Protocol;
	} Mapping[1];
} WINSOCK_MAPPING, *PWINSOCK_MAPPING;
DWORD WINAPI WSHGetWinsockMapping(PWINSOCK_MAPPING,DWORD);
typedef DWORD (WINAPI *PWSH_GET_WINSOCK_MAPPING)(PWINSOCK_MAPPING,DWORD);
#endif

#endif /* RC_INVOKED */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _WSAHELP_H */
