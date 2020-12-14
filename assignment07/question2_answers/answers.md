2.a: 396 bytes

2.b: 8196 bytes

2.c: program in main function is using the most ROM

2.d: not counting stack, it's again main function

3:

ROM usage optimization:
(1) avoid un-necessary initialization
(2) Keep Vector Interrupt Table simple -- don't define un-necessary handlers if your application doesn't need it


RAM usage optimization:
(1) reduce size of Stack -- since embedded SW is tailor made, why use more stack than what is needed? First, understand the input into the function
and later optimize it for stack usage.
(2) use const keywoard for true constants