# next数组
基础的next数组是基于最大公共前后缀计算的，最常见的定义为next\[i\]=LPS\[i-1\].
在此基础上可进行一次优化（若s\[i\]\=\=next\[i\], 则其实失配之后可以回跳到更远的地方，这就类似路径压缩）
```c++
for(int i=1;j=-1;i<=n;i++){
	while (j != -1 && pattern[i- 1] != pattern[j]){
		j= next[j];
	}
	j++;
	if (i < n && pattern[i] == pattern[j]) {
		next[i]= next[j];
	}
	else{
		next[i]=j;
	}
}
```