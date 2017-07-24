import tensorflow as tf

NUM_EPOCHS = 100

# Input --> Placeholder
X = tf.placeholder(tf.float32, [None, 3])
Y = tf.placeholder(tf.float32, [None, 1])

# Paramters --> Variables, create tf.Variables(s)
W = tf.get_variable("weights", [3, 1], initializer=tf.random_normal_initializer())
b = tf.get_variable("intercept", [1], initializer=tf.random_normal_initializer(0))

# Operations
Y_hat = tf.matmul(X, W) + b
cost = tf.reduce_mean(tf.square(Y_hat-Y))

learning_rate = 0.05
optimizer = tf.train.GradientDescentOptimizer(learning_rate).minimize(cost)

# Training
with tf.Session() as sess:
    # initialize variables
    sess.run(tf.global_variables_initializer())

    # train
    for _ in range(NUM_EPOCHS):
        for (X_batch, Y_batch) in get_minibatches(X_train, Y_train, BATCH_SIZE):
            sess.run(optimizer,
                     feed_dict = {
                         X: X_batch,
                         Y: Y_batch
                     })
