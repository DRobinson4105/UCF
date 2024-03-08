base_word = "abcdefghijklmnopqrstuvwxyzab"
words_100 = [base_word + chr(97 + (i // 26)) + chr(97 + (i % 26)) for i in range(100)]
words_120 = []
length = 1

while len(words_120) < 120:
    for i in range(26-length+1):
        words_120.append("".join([chr(97 + i + j) for j in range(length)]))
        if (len(words_120) == 120): break
    length += 1

print(100, 120)
for word in words_100:
    print(word)

for word in words_120:
    print(word)
