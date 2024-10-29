#ifndef TINY_TOR_CRYPTO_BASE_KEY_H
#define TINY_TOR_CRYPTO_BASE_KEY_H

typedef struct Key {
	void (*destroy)(struct Key* self);
} Key;

Key* KeyCreate(void);
void KeyDestroy(Key* self);

#endif // !TINY_TOR_CRYPTO_BASE_KEY_H