gcd(a,b){return b?gcd(b,a%b):a;}
main(t,a,b){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&a,&b);
        printf("%d\n",a/gcd(a,b)*b);
    }
}
