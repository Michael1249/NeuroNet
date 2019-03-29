#pragma once
#include "Layer.h"
#include <vector>
namespace perceptron
{
	using namespace neuro_layer;
	class Perceptron
	{
	public:
		Perceptron(size_t layer_count, size_t layer_size);

		const val_conteiner_t& compute(const val_conteiner_t& input);
	private:
		std::vector<Layer> layers;
	};
}
