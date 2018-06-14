#include <linux/export.h>
#include <tmem/tmem_ops.h> 

struct tmem_ops *tmem_ops = NULL;
EXPORT_SYMBOL(tmem_ops);

void register_tmem_ops(struct tmem_ops *new_ops)
{
	tmem_ops = new_ops;
}
EXPORT_SYMBOL(register_tmem_ops);


bool tmem_test(void)
{
	if (tmem_ops != NULL)
		return true;
	else
		return false;
}
EXPORT_SYMBOL(tmem_test);

int tmem_put(void *key, size_t key_len, void *val, size_t val_len)
{
	if (tmem_ops != NULL)
		return tmem_ops->put(key, key_len, val, val_len);
	else {
		pr_err("Put not implemented");
		return -ENOSYS;
	}	
}
EXPORT_SYMBOL(tmem_put);

int tmem_get(void *key, size_t key_len, void *val, size_t *val_len)
{
	if (tmem_ops != NULL)
		return tmem_ops->get(key, key_len, val, val_len);
	else {
		pr_err("Get not implemented");
		return -ENOSYS;
	}
}
EXPORT_SYMBOL(tmem_get);

void tmem_invalidate(void *key, size_t key_len)
{
	if (tmem_ops != NULL)
		tmem_ops->invalidate(key, key_len);
	else 
		pr_err("Invalidate not implemented");
}
EXPORT_SYMBOL(tmem_invalidate);

void tmem_invalidate_area(void)
{
	if (tmem_ops != NULL)
		tmem_ops->invalidate_all();
	else
		pr_err("Invalidate area not implemented");
}
EXPORT_SYMBOL(tmem_invalidate_area);

