#include <linux/unistd.h>
#include <linux/linkage.h>
#include <linux/syscalls.h>

asmlinkage long multikill(pid_t *pids, int len) {
	int i ,n,r = 0;
	for(i = 0;i< len;i++){
		if(!sys_kill(pids[i],SIGKILL)) r++;
	}
	if(len>r)
		return -1;
  	return 0;
}