#include "pch.h"
#include "Layer.h"
namespace neuro_layer
{
	Layer::Layer(size_t size) :
		state(size),
		weights(size)
	{
		for (auto& val_arr : weights)
		{
			val_conteiner_t arr(size);

			for (auto& val : arr)
			{
				val = rand() % (sampling * 2) - sampling;
				val *= 2;
			}

			val_arr = std::move(arr);
		}
	}


	void Layer::update(const val_conteiner_t& input)
	{
		size_t iter = 0;
		for (auto& val : state)
		{
			auto& this_weights = weights[iter];
			val = activationFunction((input * this_weights).sum() + this_weights[this_weights.size() - 1]);
			++iter;
		}
	}

	const val_conteiner_t & Layer::getState()
	{
		return state;
	}

	value_t activationFunction(value_t input)
	{
		float x = static_cast<float>(input);
		float exp_x = expf(x / sampling2);
		float exp_neg_x = expf(-x / sampling2);
		return static_cast<value_t>((exp_x - exp_neg_x) / (exp_x + exp_neg_x) * sampling);
	}
}