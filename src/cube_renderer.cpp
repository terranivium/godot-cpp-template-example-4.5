#include "cube_renderer.h"
#include "godot_cpp/core/class_db.hpp"

using namespace godot;

void CubeRenderer::_bind_methods() {
	// Bind property getters and setters
	ClassDB::bind_method(D_METHOD("set_rotation_speed", "speed"), &CubeRenderer::set_rotation_speed);
	ClassDB::bind_method(D_METHOD("get_rotation_speed"), &CubeRenderer::get_rotation_speed);
	
	ClassDB::bind_method(D_METHOD("set_cube_color", "color"), &CubeRenderer::set_cube_color);
	ClassDB::bind_method(D_METHOD("get_cube_color"), &CubeRenderer::get_cube_color);
	
	// Add properties to the editor
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "rotation_speed", PROPERTY_HINT_RANGE, "0,10,0.1"), "set_rotation_speed", "get_rotation_speed");
	ADD_PROPERTY(PropertyInfo(Variant::COLOR, "cube_color"), "set_cube_color", "get_cube_color");
}

CubeRenderer::CubeRenderer() {
	mesh_instance = nullptr;
	box_mesh = nullptr;
	material = nullptr;
	rotation_speed = 1.0f;
	cube_color = Color(0.8f, 0.2f, 0.2f, 1.0f); // Red color
}

CubeRenderer::~CubeRenderer() {
	// Cleanup is handled by Godot's reference counting
}

void CubeRenderer::_ready() {
	// Create the mesh instance
	mesh_instance = memnew(MeshInstance3D);
	add_child(mesh_instance);
	
	// Create the box mesh
	box_mesh = memnew(BoxMesh);
	box_mesh->set_size(Vector3(2.0f, 2.0f, 2.0f)); // 2x2x2 cube
	mesh_instance->set_mesh(box_mesh);
	
	// Create the material
	material = memnew(StandardMaterial3D);
	material->set_albedo(cube_color);
	material->set_metallic(0.0f);
	material->set_roughness(0.3f);
	mesh_instance->set_surface_override_material(0, material);
	
	print_line("CubeRenderer: 3D cube created and ready!");
}

void CubeRenderer::_process(double delta) {
	// Rotate the cube
	rotate_y(rotation_speed * delta);
}

void CubeRenderer::set_rotation_speed(float speed) {
	rotation_speed = speed;
}

float CubeRenderer::get_rotation_speed() const {
	return rotation_speed;
}

void CubeRenderer::set_cube_color(Color color) {
	cube_color = color;
	if (material) {
		material->set_albedo(color);
	}
}

Color CubeRenderer::get_cube_color() const {
	return cube_color;
}
