#ifndef _CURRENT_BACKUPS_H
#define _CURRENT_BACKUPS_H

struct bu
{
	char *path;
	char *data;
	char *delta;
	char *timestamp;
	char *forward_timestamp;
	unsigned long index;
	unsigned long forward_index;
};

extern int recursive_hardlink(const char *src, const char *dst, const char *client, struct cntr *cntr);
extern int recursive_delete(const char *d, const char *file, bool delfiles);
extern void free_current_backups(struct bu **arr, int a);
extern int get_current_backups(const char *basedir, struct bu **arr, int *a);
extern int get_new_timestamp(const char *basedir, char *buf, size_t s);
extern int read_timestamp(const char *path, char buf[], size_t len);
extern int write_timestamp(const char *timestamp, const char *tstmp);
extern int compress_file(const char *current, const char *file);
extern int compress_filename(const char *d, const char *file, const char *zfile);
extern int remove_old_backups(const char *basedir, int keep);
extern int compile_regex(regex_t **regex, const char *str);
extern int check_regex(regex_t *regex, const char *buf);
extern pid_t forkchild_fd(int sin, int sout, int serr,
	const char *path, char * const argv[]);
extern pid_t forkchild(FILE **sin, FILE **sout, FILE **serr,
	const char *path, char * const argv[]);

#endif // _CURRENT_BACKUPS_H
