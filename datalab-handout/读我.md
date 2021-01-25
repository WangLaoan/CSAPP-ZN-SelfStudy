# 任务目标
修改bits.c, 完成所有函数api 的实现，通过dlc(规则测试),和btest(功能测试)

# 初始化
1. 更改Makefile
```
// 32位编译 替换 64位编译 （PC是32位的可跳过）
CFLAGS = -O -Wall -m32  	-> 		CFLAGS = -O -Wall -m64
```

2. make btest // 构建测试程序

# 完成练习
1. 修改bits.c， 完成函数API
2. unix> ./btest -g		//测试得分
3. unix> ./dlc bits.c 	//检查是否符合题目规则
4. 继续 步骤1. 直到所有练习完成

