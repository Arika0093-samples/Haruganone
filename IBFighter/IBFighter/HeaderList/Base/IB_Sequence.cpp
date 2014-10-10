// --------------------------------------------------------
//	IB_Sequencer.cpp
// --------------------------------------------------------
//	IB_Sequencer.hpp のメンバ関数の実体を置く
// --------------------------------------------------------
#include "IB_BaseInclude.hpp"

// ----------------------------------------------------
//	Sequencer
// ----------------------------------------------------
//	Sequencer::Sequencer (Constructor)
// ----------------------------------------------------
				Sequencer::Sequencer()
{
	this->Sequencer::Sequencer(0);
}

// ----------------------------------------------------
//	Sequencer::Sequencer (Constructor)
// ----------------------------------------------------
				Sequencer::Sequencer(unsigned int Stat)
{
	_Status = Stat;
	_SeqChanged = 0;
}

// ----------------------------------------------------
//	Sequencer::Process
// ----------------------------------------------------
unsigned int	Sequencer::Process()
{
	// 初期化
	_SeqChanged = 0;
	// 存在確認を行い存在するなら実行
	if(_FuncList.count(_Status) != 0){
		_FuncList[_Status](*this);
	}
	return _SeqChanged;
}

// ----------------------------------------------------
//	Sequencer::RegistFunction
// ----------------------------------------------------
void			Sequencer::RegistFunction(unsigned int Stat, function<void(Sequencer&)> Fc)
{
	// 存在確認
	if(_FuncList.count(Stat) != 0){
		// 存在する場合値を書き換える
		_FuncList[Stat] = Fc;
	}
	else {
		// 存在しない場合挿入する
		_FuncList.insert(
			std::map<unsigned int, function<void(Sequencer&)>>::value_type(Stat, Fc));
	}
	return;
}

// ----------------------------------------------------
//	Sequencer::GetStatus
// ----------------------------------------------------
unsigned		Sequencer::GetStatus() const
{
	return _Status;
}

// ----------------------------------------------------
//	Sequencer::SetStatus
// ----------------------------------------------------
void			Sequencer::SetStatus(unsigned int Stat)
{
	_Status = _SeqChanged = Stat;
}

