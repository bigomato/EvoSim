class Brain:
    nodes = []          # Neuronen
    connections = []    # Synapsen

    def add_node(self, node):     # Neuron hinzufügen
        self.nodes.append(node)

    def add_connection(self, connection):  # Synapse hinzufügen
        self.connections.append(connection)

    def get_node(self, id):     # Neuron abfragen
        for node in self.nodes:
            if node.id == id:
                return node

    def input_node_values(self, values):   # Inputwerte setzen
        # map of node id to value, for example sensor values (input nodes)
        # e.g. {1: 0.5, 2: 0.3}
        node_values = {}
        for value in values:
            node_values[value[0]] = value[1]
        print(f"{node_values = }")
        print(f"{values = }")
        # input values to input nodes
        for node in self.nodes:
            if node.type == 'input':
                node.value = node_values[node.id]
    
    def feed_forward(self):
        # feed forward
        for node in self.nodes:
            if node.type == 'hidden' or node.type == 'output':
                node.value = 0
                for connection in self.connections:
                    if connection.to_node == node.id:
                        from_node = self.get_node(connection.from_node)
                        node.value += from_node.value
                node.value = node.activation_function(node.value + node.bias)


    def visualize(self):
        # visualize the brain
        import networkx as nx
        import matplotlib.pyplot as plt

        # Create a directed graph
        G = nx.DiGraph()

        # Add nodes to the graph
        for node in brain.nodes:
            G.add_node(node.id, type=node.type)

        # Add edges to the graph
        for connection in brain.connections:
            G.add_edge(connection.from_node, connection.to_node)

        # Draw the graph
        pos = nx.spring_layout(G)
        nx.draw(G, pos, with_labels=True, node_color='skyblue', node_size=1500, edge_color='g', width=3, alpha=0.6, arrowsize=30)
        plt.show()



import math


class Node:
    # default sigmoid activation function
    def __init__(self, id, type, activation_function=lambda x: 1 / (1 + math.exp(-x))):
        self.id = id
        self.type = type
        self.activation_function = activation_function
        self.value = 0
        self.bias = 0


class Connection:
    def __init__(self, id, from_node, to_node):
        self.id = id
        self.from_node = from_node
        self.to_node = to_node


# example usage
brain = Brain()
brain.add_node(Node(1, 'input'))
brain.add_node(Node(2, 'input'))
brain.add_node(Node(3, 'hidden'))
brain.add_node(Node(4, 'output'))
brain.add_connection(Connection(1, 1, 3))
brain.add_connection(Connection(2, 2, 3))
brain.add_connection(Connection(3, 3, 4))
brain.input_node_values([(1, 0.5), (2, 0.3)])
brain.feed_forward()
print(brain.get_node(4).value)

# visualize the brain
brain.visualize()