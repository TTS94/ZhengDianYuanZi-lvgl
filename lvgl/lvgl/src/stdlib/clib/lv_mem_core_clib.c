/**
 * @file lv_mem_core_clib.c
 */

/*********************
 *      INCLUDES
 *********************/
#include "../lv_mem.h"
#if LV_USE_STDLIB_MALLOC == LV_STDLIB_CLIB
#include "../../stdlib/lv_mem.h"
#include <stdlib.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/
/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_mem_init(void)
{
    return; /*Nothing to init*/
}

void lv_mem_deinit(void)
{
    return; /*Nothing to deinit*/

}

lv_mem_pool_t lv_mem_add_pool(void * mem, size_t bytes)
{
    /*Not supported*/
    LV_UNUSED(mem);
    LV_UNUSED(bytes);
    return NULL;
}

void lv_mem_remove_pool(lv_mem_pool_t pool)
{
    /*Not supported*/
    LV_UNUSED(pool);
    return;
}

void * lv_malloc_core(size_t size)
{
    return malloc(size);
}

void * lv_realloc_core(void * p, size_t new_size)
{
    return realloc(p, new_size);
}

void lv_free_core(void * p)
{
    free(p);
}

#include "FreeRTOSConfig.h"

void lv_mem_monitor_core(lv_mem_monitor_t * mon_p)
{
    /*Not supported*/
    // LV_UNUSED(mon_p);
// 1. 设置总堆大小 (根据你的 FreeRTOS 配置)
    mon_p->total_size = configTOTAL_HEAP_SIZE; 
    
    // 2. 获取当前剩余内存
    mon_p->free_size = xPortGetFreeHeapSize(); 
    
    // 3. 计算已用空间
    uint32_t used_size = mon_p->total_size - mon_p->free_size;
    
    // 4. 计算百分比
    if(mon_p->total_size > 0) {
        mon_p->used_pct = (used_size * 100) / mon_p->total_size;
    } else {
        mon_p->used_pct = 0;
    }
    
    // 5. 最大消耗记录（如果支持，不支持可设为 0）
    mon_p->max_used = 0;
    return;
}

lv_result_t lv_mem_test_core(void)
{
    /*Not supported*/
    return LV_RESULT_OK;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /*LV_STDLIB_CLIB*/
