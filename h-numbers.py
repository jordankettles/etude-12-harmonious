import math

sum_dict = dict()

def find_sum_of_divisors(n):
    global sum_dict
    sum = 0
    for i in range(2, n//2 + 2):
        if n % i == 0:
            # if i in sum_dict.keys():
            #     sum += sum_dict[i]
            #     break
            # else:
            sum += n//i

    return sum

# division is transitive.

if __name__ == "__main__":
    for i in range(1, 200000):
        # print(sum_dict)
        if i in sum_dict.keys():
            continue
        j = find_sum_of_divisors(i)
        sum_dict[i] = j
        if i == 1575:
            print("asdasd")
        # if j in sum_dict.keys():
        #     sum_of_j = sum_dict[j]
        # else:
        sum_of_j = find_sum_of_divisors(j)

        if sum_of_j == i:
            print(str(i) + " " + str(j))
