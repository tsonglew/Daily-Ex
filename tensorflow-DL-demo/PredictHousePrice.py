import numpy

# Input Features: floor area, distance from public transport, number of rooms
X_train = numpy.array([
    [1250, 350, 3],
    [1700, 900, 6],
    [1400, 600, 3]
])

# Housing Price
Y_train = numpy.array([345000, 580000, 360000])

# Model Parameters
weights = numpy.array([300, -10, -1])
intercept = -26497

def model(X, weights, intercept):
    return X.dot(weights) + intercept

Y_hat = model(X_train, weights, intercept)

print Y_hat