#ifndef _TMEM_OPS_H
#define _TMEM_OPS_H

#include <linux/mm.h>
#include <uapi/tmem/tmem.h>


/* KVM Hypercall commands */
#define PV_TMEM_GET_OP		0	
#define PV_TMEM_PUT_OP		1
#define PV_TMEM_INVALIDATE_OP	2

#define TCTRL_DUMMY_BIT (1UL << 0)
#define TCTRL_SLEEPY_BIT (1UL << 1)
#define TCTRL_SILENT_BIT (1UL << 2)
#define TCTRL_GENERATE_BIT (1UL << 3)

#define SLEEP_USECS	  (100)
#define SLEEP_USECS_SLACK (10)

struct tmem_ops {
	void (*init)(unsigned);
	int (*put)(void *key, size_t key_len, void *val, size_t val_len);
	int (*get)(void *key, size_t key_len, void *val, size_t *val_len);
	void (*invalidate)(void *key, size_t key_len);
	void (*invalidate_all)(void);
};

extern struct tmem_ops *tmem_ops;

extern inline void register_tmem_ops(struct tmem_ops *);
extern inline bool tmem_test(void);
extern inline int tmem_put(void *key, size_t key_len, void *val, size_t val_len);
extern inline int tmem_get(void *key, size_t key_len, void *val, size_t *val_len);
extern inline void tmem_invalidate(void *key, size_t key_len);
extern inline void tmem_invalidate_area(void);


#endif /* _TMEM_OPS_H */
