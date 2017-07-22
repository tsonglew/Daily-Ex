import numpy

NUM_EPOCHS = 100
# Input Features: floor area, distance from public transport, number of rooms
X_train = numpy.array([
    [1250, 350, 3],
    [1700, 900, 6],
    [1400, 600, 3]
])

# Housing Price
Y_train = numpy.array([345000, 580000, 360000])

# Model Parameters
learning_rate = 0.05

# Model -- Operations
def model(X, weights, intercept):
    return X.dot(weights) + intercept

# Model -- Cost Function
def cost(Y_hat, Y):
    return numpy.sum((Y_hat - Y)**2)

# Training
def training_round(x, y, weights, intercept, alpha=learning_rate):
    # calculate estimate
    y_hat = model(x, weights, intercept)

    # calculate error
    delta_y = y - y_hat

    # calculate gradients
    gradient_weight = -2 * delta_y * weights
    gradient_intercept = -2 * delta_y

    # update parameter
    weights = weights - alpha * gradient_weight
    intercept = intercept - alpha * gradient_intercept

    return weights, intercept

def train(X, Y):
    # initialize parameter
    weights = numpy.random.randn(3)
    intercept = 0

    # training rounds
    for i in range(NUM_EPOCHS):
        for (x, y) in zip(X, Y):
            weights, intercept = training_round(x, y, weights, intercept)

def test(X_test, Y_test, weights, intercept):
    Y_predicted = model(X_test, weights, intercept)
    error = cost(Y_predicted, Y_test)
    return numpy.sqrt(numpy.mean(error))

test(X_test, Y_test, final_weights, final_intercept)