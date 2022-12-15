#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#define handle_error_en(en, msg)\
{\
       	errno = en; \
	perror(msg); \
	exit(EXIT_FAILURE);\
} 

static void *thread_func(void *ignored_argument)
{
	int s;

	/* 让暂时不能取消线程 */

	s = pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	if (s != 0)
		handle_error_en(s, "pthread_setcancelstate");

	printf("thread_func(): 此时不能取消线程\n");

	/* 给时间让取消线程*/
	sleep(3);
        /*while(1)
	{
	}*/

	printf("thread_func(): 此时可以取消线程\n");
	s = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	if (s != 0)
		handle_error_en(s, "pthread_setcancelstate");

	/* sleep() is a cancellation point */

	sleep(10);        /* Should get canceled while we sleep */

	/* Should never get here */

	printf("thread_func(): not canceled!\n");
	return NULL;
}
int main(void)
{
	pthread_t thr;
	void *res;
	int s;

	/* 创建线程 */

	s = pthread_create(&thr, NULL, &thread_func, NULL);
	if (s != 0)
		handle_error_en(s, "pthread_create");

	 /* 线程开始 */
	sleep(2);
	printf("main():取消线程\n");
	s = pthread_cancel(thr);
	if (s != 0)
		handle_error_en(s, "pthread_cancel");

	/* 阻塞线程 查看退出线程状态 */

	s = pthread_join(thr, &res);
	if (s != 0)
		handle_error_en(s, "pthread_join");

	if (res == PTHREAD_CANCELED)
		printf("main(): 线程取消成功\n");
	else
		printf("main(): thread wasn't canceled (shouldn't happen!)\n");
	exit(EXIT_SUCCESS);
}

