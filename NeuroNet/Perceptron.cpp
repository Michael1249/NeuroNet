#include "pch.h"
#include "Perceptron.h"

namespace perceptron 
{
	Perceptron::Perceptron(size_t layer_count, size_t layer_size) :
		layers(layer_count, layer_size)
	{
	}

	const val_conteiner_t & Perceptron::compute(const val_conteiner_t & input)
	{
		auto iter = layers.begin();
		iter->update(input);
		++iter;
		for (; iter != layers.end(); ++iter)
		{
			iter->update((iter - 1)->getState());
		}
		return layers.rbegin()->getState();
	}
}
