import tensorflow as tf 

# Constants are initialized when calling tf.constant
node1 = tf.constant(3.0, dtype=tf.float32)
node2 = tf.constant(4.0)    # also tf.float32 implicitly
# print(node1, node2)

sess = tf.Session()
# print(sess.run([node1, node2]))

node3 = tf.add(node1, node2)
#print("node3:", node3)
#print("sess.run(node3):", sess.run(node3))

a = tf.placeholder(tf.float32)
b = tf.placeholder(tf.float32)
addr_node = a + b

#print(sess.run(addr_node, {a: 3, b: 4}))
#print(sess.run(addr_node, {a: [1, 3], b: [2, 4]}))
add_and_triple = addr_node * 3
#print(sess.run(add_and_triple, {a: 3, b: 4.5}))

W = tf.Variable([.3], dtype=tf.float32)
b = tf.Variable([-.3], dtype=tf.float32)
x = tf.placeholder(tf.float32)
linear_model = W * x + b

# Initialize variables
init = tf.global_variables_initializer()
sess.run(init)

print(sess.run(linear_model, {x: [1, 2, 3, 4]}))

y = tf.placeholder(tf.float32)
squared_deltas = tf.square(y - linear_model)
loss = tf.reduce_sum(squared_deltas)
print(sess.run(loss, {x:[1,2,3,4], y:[0,-1,-2,-3]}))