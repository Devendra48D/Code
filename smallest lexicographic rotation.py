def smallest(word):
    size = len(word)
    min_word = word
    word = word + word
    for i in range(0, size):
        curr = word[i:i+size]
        min_word = min(min_word, curr)
    return min_word
