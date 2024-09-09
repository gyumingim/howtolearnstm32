#include "main.h"
/* USER CODE BEGIN PV */
uint8_t help[] = {0x76, 0x79, 0x38, 0x73};
/* USER CODE END PV */
/* USER CODE BEGIN 0 */
typedef struct fnd {
  GPIO_TypeDef *port;
  uint16_t pin;
} FND;
FND value[8] = {
  {GPIOB, GPIO_PIN_0}, {GPIOB, GPIO_PIN_1},
  {GPIOB, GPIO_PIN_2}, {GPIOB, GPIO_PIN_3},
  {GPIOB, GPIO_PIN_4}, {GPIOB, GPIO_PIN_5},
  {GPIOB, GPIO_PIN_6}, {GPIOB, GPIO_PIN_7}
};
FND sel[4] = {
  {GPIOA, GPIO_PIN_10}, {GPIOA, GPIO_PIN_11},
  {GPIOC, GPIO_PIN_4}, {GPIOC, GPIO_PIN_3}
};
void display_fnd(uint8_t data, uint8_t position, uint32_t time) {
  uint32_t i;
  for (i = 0; i < 4; i++) {
    if(i == position)
      HAL_GPIO_WritePin(sel[i].port, sel[i].pin, 1);
    else
      HAL_GPIO_WritePin(sel[i].port, sel[i].pin, 0);
  }
 for(i = 0; i < 8; i++) {
    if((data & (1 << i)) != 0)
      HAL_GPIO_WritePin(value[i].port, value[i].pin, 1);
    else
      HAL_GPIO_WritePin(value[i].port, value[i].pin, 0);
  }
  HAL_Delay(time);
}
/* USER CODE BEGIN 0 */

int main(void) {
/* USER CODE BEGIN WHILE */
  while(1) {
    display_fnd(help[0], 3, 5);
    display_fnd(help[1], 2, 5);
    display_fnd(help[2], 1, 5);
    display_fnd(help[3], 0, 5);
    /* USER CODE END WHILE */
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}







