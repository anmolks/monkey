/*  Monkey HTTP Daemon
 *  ------------------
 *  Copyright (C) 2001-2003, Eduardo Silva P.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef MK_LOGFILE_H
#define MK_LOGFILE_H

/* s_log status */
#define S_LOG_ON 0
#define S_LOG_OFF 1

/* logfile.c */
pthread_mutex_t mutex_log_queue;

struct log_queue {
    struct log_info *info;
    struct log_queue *next;
};
struct log_queue *_log_queue;

struct log_info {
    int method;
    int protocol;
    mk_pointer uri;

	char *ip;
	char *datetime;
	int   final_response; /* Ok: 200, Not Found 400, etc... */
	int   size;
	int   status; /* on/off : 301. */
	char  *error_msg;
    struct host *host_conf;
};

char    *PutTime();
char    *PutIP();
char    *BaseName(char *name);
int	 write_log(struct log_info *log, int host_pipe);
int	 add_log_pid();
int	 remove_log_pid();

void *start_worker_logger(void *args);
int logger_add_request(struct log_info *log);

#endif

