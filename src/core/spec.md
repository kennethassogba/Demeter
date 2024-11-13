# Spec

The most effective way of getting early adopters is to be a drop-in replacement for OpenMOC (eventually OpenMC).
This also simplifies the specification of the geometry sub-module.

## Usage example

```python
# Initialize material cross sections using NumPy data arrays
sigma_t = np.array([0.1,0.15,0.2,0.25,0.35,0.4,0.45,0.5])
sigma_f = np.array([0.05,0.1,0.15,0.2,0.25,0.3,0.35,0.4])

# Instantiate an OpenMOC Material class object with an optional string name
material = Material(sigma_t, sigma_f, name='test material')

# 4.3% MOX pin cell
mox43 = Cell(rings=3, sectors=8)
mox43.setMaterial(material)
```

## Geometry

Lets the user describe the geometry of the problem.

Cell
PinCell(dx (sca), dy (sca), radii, mats, pitch, pitch)
Lattice(dx (vec), dy (vec))
  symetry 1/2 1/8

Point
Edge

## Material and Cross section

Material : store the cross section of a material
  vec total or transport sigma_t
  vec absorption sigma_a
  mat scattering sigma_s
  vec fission sigma_f
  vec nu*fission v*sigma_f
  sca chi
  str name (optional)

## Mesh

Utilisee par le solveur pour les calculs. La geometrie est convertie en maillage.

Point
Edge
