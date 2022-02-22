def minimalOperations(word_collection):
    counter = []
    for words in word_collection:
        words = list(words)
        count = 0
        i = 0
        while i < len(words)-1:
            if words[i] == words[i+1]:
                count += 1
                i += 1
            i += 1
        counter.append(count)
    return counter

words = ["ab", "aab", "abb", "abab", "abaaaba"]
print(minimalOperations(words))