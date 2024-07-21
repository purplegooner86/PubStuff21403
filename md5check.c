// gcc md5check.c -Wno-deprecated-declarations -o md5check -lcrypto

#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>

void calculate_md5(const char *str, unsigned char *digest) {
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, str, strlen(str));
    MD5_Final(digest, &ctx);
}

int main() {
    const char *message = "Hello, world";
    unsigned char digest[MD5_DIGEST_LENGTH];

    for (int i = 0; i < 2000000; i++) {
        calculate_md5(message, digest);

        if (i % 1000 == 0) {
            printf("i = %d\n", i);
        }
    }

    printf("Digest: %02x", digest[0]);
    printf("%02x\n", digest[1]);

    return 0;
}