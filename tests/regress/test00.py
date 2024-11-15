from demeter import *
import numpy as np
import matplotlib.pyplot as plt

# Create materials
sigma_t = np.array([0.1, 0.2, 0.3])
sigma_f = np.array([0.01, 0.02, 0.03]),
sigma_a = np.array([0.001, 0.002, 0.003])
uO2 = Material(sigma_t, sigma_f, sigma_a, name= 'uO2')

sigma_t = np.array([0.1, 0.2, 0.3])
sigma_f = np.array([0.01, 0.02, 0.03]),
sigma_a = np.array([0.001, 0.002, 0.003])
h20 = Material(sigma_t, sigma_f, sigma_a, name= 'H20')

# Create pin cells
uO2_cell = PinCell(0.5, uO2)
h2O_cell = PinCell(0.5, h20)

# Create assembly
dx = np.array([10., 20.])
dy = np.array([10., 20.])
motif = [uO2_cell, uO2_cell,
        h2O_cell, h2O_cell]
assembly = Lattice(motif, dx, dy)

# Create core
core = Lattice([assembly]) # => deduction des tailles
# core.refineMesh(2)
# core.getXMin().setBoundaryCondition(BoundaryCondition.Vacuum)
# core.getXMax().setBoundaryCondition(BoundaryCondition.Reflection)

# Maybe an intermediate geometry class that handles core or assembly

# Create solver
solver = Solver(core, 4, 10)

# Set boundary conditions
# solver.setBoundaryCondition(BoundaryCondition.Vacuum, BoundarySide.Left)
# solver.setBoundaryCondition(BoundaryCondition.Reflection, BoundarySide.Right)

# Solve the transport equation
solver.solve()

# Access data
print(f"Core has {len(core.getAssemblies())} assemblies")
print(f"Assembly has {len(core.getAssemblies()[0].getPinCells())} pin cells")
print(f"Pin cell radius: {core.getAssemblies()[0].getPinCells()[0].getRadius()}")
print(f"Material total cross section: {core.getAssemblies()[0].getPinCells()[0].getMaterial().getCrossSection().getTotal()}")

# Get flux data
flux = solver.getFlux()

# Plot geometry and flux
fig, ax = plt.subplots()

# Plot pin cells
for i, assembly in enumerate(core.getAssemblies()):
  for j, pin_cell in enumerate(assembly.getPinCells()):
    circle = plt.Circle((i, j), pin_cell.getRadius(), edgecolor='black', facecolor='none')
    ax.add_artist(circle)

# Plot flux
flux_array = np.array(flux)
cax = ax.matshow(flux_array, cmap='viridis')

# Add colorbar
fig.colorbar(cax)

# Set plot limits and labels
ax.set_xlim(-1, len(core.getAssemblies()))
ax.set_ylim(-1, len(core.getAssemblies()[0].getPinCells()))
ax.set_xlabel('Assembly Index')
ax.set_ylabel('Pin Cell Index')
ax.set_title('Flux Distribution')

plt.show()