
# P93
# s = []
# for i in range(11):
#     s.append(0)

# line = input().strip().split(' ')
# for num in line:
#     s[int(int(num)/10)] += 1

# print(s) #[0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1]

#3.17
# while True:
#     try:
#         line = input().strip().split(' ')
#         for word in line:
#             word = word.upper()
#             print(word)
#     except:
#         break

#3.20
while True:
    try:
        line = input().strip().split(' ')
        nums = []
        for num in line:
            nums.append(int(num))

        for i in range(0,len(nums)-1,2):
            print(nums[i] + nums[i+1])
        if len(nums) % 2 != 0:
            print(nums[-1])

        for i in range(int(len(nums)/2)):
            print(nums[i] + nums[-i-1])
        if len(nums) % 2 != 0:
            print(nums[int(len(nums)/2)])
    except:
        break


