/*-------------------------------------------------------------------------
 *
 * hba.h
 *	  Interface to hba.c
 *
 *
 * $Id: hba.h,v 1.15 1999/09/27 03:13:10 momjian Exp $
 *
 *-------------------------------------------------------------------------
 */
#ifndef HBA_H
#define HBA_H

#include <netinet/in.h>

#include "libpq/pqcomm.h"

#define CONF_FILE "pg_hba.conf"
 /* Name of the config file  */

#define USERMAP_FILE "pg_ident.conf"
 /* Name of the usermap file */

#define OLD_CONF_FILE "pg_hba"
 /* Name of the config file in prior releases of Postgres. */

#define MAX_LINES 255
 /* Maximum number of config lines that can apply to one database	 */

#define MAX_TOKEN 80
/* Maximum size of one token in the configuration file	*/

#define MAX_AUTH_ARG	80		/* Max size of an authentication arg */

#define IDENT_PORT 113
 /* Standard TCP port number for Ident service.  Assigned by IANA */

#define IDENT_USERNAME_MAX 512
 /* Max size of username ident server can return */

typedef enum UserAuth
{
	uaReject,
	uaKrb4,
	uaKrb5,
	uaTrust,
	uaIdent,
	uaPassword,
	uaCrypt
} UserAuth;

typedef struct Port hbaPort;

int hba_getauthmethod(hbaPort *port);
int authident(struct sockaddr_in * raddr, struct sockaddr_in * laddr,
		  const char *postgres_username, const char *auth_arg);

#endif
