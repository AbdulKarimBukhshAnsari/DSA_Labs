import matplotlib.pyplot as plt
import os

# Example data: X and Y values for the graph
x = [1, 2, 3, 4, 5]
y = [2, 3, 5, 7, 11]

# Create the plot
plt.plot(x, y, label='Prime Numbers', marker='o')

# Adding labels
plt.title('Simple Line Plot')
plt.xlabel('X-Axis (1 to 5)')
plt.ylabel('Y-Axis (Prime Numbers)')

# Adding a legend
plt.legend()

# Get the current directory where the script is located
current_directory = os.path.dirname(os.path.abspath(__file__))

# Create the full path for the plot file
plot_path = os.path.join(current_directory, "plot.png")

# Save the plot
plt.savefig(plot_path)

# Optionally, close the plot to free resources
plt.show()


print(f"Plot saved to {plot_path}")  # This line will confirm where the plot is saved


