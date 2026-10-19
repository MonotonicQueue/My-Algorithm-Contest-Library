
for(int i=2,j=0;i<=n;i++){
	while(j && s[i] != s[j+1]) j = kmp[j];
	if(s[i] == s[j+1]) j++;
	kmp[i] = j;
}
