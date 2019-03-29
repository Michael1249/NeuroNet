#pragma once
#include <valarray>
#include <vector>
namespace neuro_layer
{
	using value_t = int32_t;
	using val_conteiner_t = std::valarray<value_t>;
	using weights_t = std::vector<val_conteiner_t>;
	const size_t sampling = 10000;
	const size_t sampling2 = sampling * sampling;

	value_t activationFunction(value_t input);

	class Layer
	{
	public:
		Layer(size_t size);

		void update(const val_conteiner_t& input);
		const val_conteiner_t& getState();
	private:
		val_conteiner_t state;
		weights_t weights;
	};
}
