#ifndef _BURP_SSL_H
#define _BURP_SSL_H

extern SSL_CTX *ssl_initialise_ctx(struct config *conf);
extern void ssl_destroy_ctx(SSL_CTX *ctx);
extern int ssl_load_dh_params(SSL_CTX *ctx, struct config *conf);
extern SSL_CTX *berr_exit(const char *string);
extern void ssl_load_globals(void);
extern int ssl_check_cert(SSL *ssl, struct config *conf);

#endif
