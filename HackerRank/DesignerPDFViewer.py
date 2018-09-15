# Complete the designerPdfViewer function below.
def designerPdfViewer(h, word):
    lookup = dict(zip(list("abcdefghijklmnopqrstuvwxyz"), h))
    ht = max(lookup[x] for x in word)
    wd = len(word)
    return ht * wd
