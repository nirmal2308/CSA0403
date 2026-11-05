#ifndef CRYPTO_H
#define CRYPTO_H

const char *crypto_version(void);
void encrypt_buf(char *buf, int n, char key);

#endif
