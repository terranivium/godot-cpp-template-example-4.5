#pragma once

#include "godot_cpp/classes/node3d.hpp"
#include "godot_cpp/classes/mesh_instance3d.hpp"
#include "godot_cpp/classes/box_mesh.hpp"
#include "godot_cpp/classes/standard_material3d.hpp"
#include "godot_cpp/variant/variant.hpp"

using namespace godot;

class CubeRenderer : public Node3D {
	GDCLASS(CubeRenderer, Node3D)

private:
	MeshInstance3D* mesh_instance;
	BoxMesh* box_mesh;
	StandardMaterial3D* material;
	
	float rotation_speed;
	Color cube_color;

protected:
	static void _bind_methods();

public:
	CubeRenderer();
	~CubeRenderer() override;

	void _ready() override;
	void _process(double delta) override;
	
	// Properties
	void set_rotation_speed(float speed);
	float get_rotation_speed() const;
	
	void set_cube_color(Color color);
	Color get_cube_color() const;
};
