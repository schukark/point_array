// Проверка на подключение заголовочного файла в единственном экземпляре
#ifndef CPP_POINT_H
#define CPP_POINT_H

namespace taskPoint
{
	/** \brief Точка с двумя целочисленными координатами.
	 *
	 *  Координаты точки бесконечны, за значением INT32_MAX следует значение INT32_MIN.
	 */
	class Point
	{
	public:
		/// Конструктор инициализирует объект точки двумя координатами.
		Point();
		explicit Point(int x, int y = 0);

		Point(const Point& other) = default;
		Point& operator=(const Point& other) = default;
		~Point() = default;

		Point& operator+=(const Point& other);
		Point& operator-=(const Point& other);
		Point operator-(const Point& right);
		Point operator-();
		bool operator==(const Point& right);


		/// Сдвигает координаты, добавляя заданные значения соответствующих координат xSh и ySh.
		void shift(int xSh, int ySh);


		int getX() const;
		int getY() const;

		void setX(int x);
		void setY(int y);

	private:
		int x_;
		int y_;
	};
}

#endif //CPP_POINT_H
