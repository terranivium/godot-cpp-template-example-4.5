extends Node3D


func _ready() -> void:
	# Create a CubeRenderer (your C++ class)
	var cube := CubeRenderer.new()
	add_child(cube)
	
	# Set some properties
	cube.rotation_speed = 2.0
	cube.cube_color = Color.BLUE
	
	print("CubeRenderer created and added to scene!")
